// httpd_lib.cpp : スタティック ライブラリ用の関数を定義します。
//

#include "httpd.h"

#define MAX (1)

T_HTTP_SOCKET* e_gThsp = NULL;
T_HTTP_SOCKET* d_gThsp = NULL;

int		empty()
{
	return d_gThsp == NULL;
}

int		en_queue(int x)
{
	T_HTTP_SOCKET* next;

	next = (T_HTTP_SOCKET *)malloc(sizeof(T_HTTP_SOCKET));
	if (next != NULL) { /* メモリが確保できないと NULL が返される */
		WSAStartup(MAKEWORD(2, 0), &next->wsaData);
		next->s_sock = socket(AF_INET, SOCK_STREAM, 0);
		if (next->s_sock == INVALID_SOCKET) {
			printf("socket : %d\n", WSAGetLastError());
			return 1;
		}
		next->sid = x;
		next->server_addr.sin_family = AF_INET;
		next->server_addr.sin_port = htons(12345);
		next->server_addr.sin_addr.S_un.S_addr = INADDR_ANY;
		next->yes = 1;
		setsockopt(next->s_sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&next->yes, sizeof(next->yes));
		
		if (bind(next->s_sock, (struct sockaddr*)&next->server_addr, sizeof(next->server_addr)) != 0) {
			printf("bind : %d\n", WSAGetLastError());
			return 1;
		}

		if (listen(next->s_sock, 5) != 0) {
			printf("listen : %d\n", WSAGetLastError());
			return 1;
		}
		next->p = NULL;
		/* 先頭であれば */
		if (d_gThsp == NULL) {
			d_gThsp = next;
		}
		/* 先頭以外であれば */
		else {
			e_gThsp->p = next;
		}
		e_gThsp = next;
		return 1;
	}
	else {
		return 0;
	}

}

int		de_queue()
{
	T_HTTP_SOCKET*	next;

	if (!empty()) {
		WSACleanup();
		next = d_gThsp->p;
		free(d_gThsp);
		d_gThsp = next;
		return 1;
	}
	else {
		/* データがなければ0を返却 */
		return 0;
	}

}

T_HTTP_SOCKET*	take_queue(SOCKETID id)
{
	T_HTTP_SOCKET* next = d_gThsp;

	if (!empty()) {
		while (next != NULL) {
			if (next->sid == id) {
				break;
			}
			next = next->p;
		}
	}
	else {
		/* データがなければ0を返却 */
		return NULL;
	}

	return next;
}

int	init_httpd(int x)
{
	int ret = 0;

	for (int i = 0; i < x; i++) {
		if (en_queue(i+1)) {
			ret += 1;
		}
	}
	return ret;
}

int close_httpd(int x)
{
	int ret = 0;

	for (int i = 0; i < x; i++) {
		if (de_queue()) {
			ret += 1;
		}
	}
	return ret;
}

int httpd_main(void)
{
	T_HTTP_SOCKET* p = NULL;

	char buf[2048];
	char inbuf[2048];

	if (init_httpd(MAX) <= 0) {
		return 0;
	}

	p = take_queue(1);

	// 応答用HTTPメッセージ作成
	memset(buf, 0, sizeof(buf));
	snprintf(buf, sizeof(buf),
		"HTTP/1.0 200 OK\r\n"
		"Content-Length: 20\r\n"
		"Content-Type: text/html\r\n"
		"\r\n"
		"HELLO\r\n");

	while (1) {
		p->len = sizeof(p->client_addr);
		p->c_sock = accept(p->s_sock, (struct sockaddr*)&p->client_addr, &p->len);
		if (p->c_sock == INVALID_SOCKET) {
			printf("accept : %d\n", WSAGetLastError());
			break;
		}

		memset(inbuf, 0, sizeof(inbuf));
		recv(p->c_sock, inbuf, sizeof(inbuf), 0);
		// 本来ならばクライアントからの要求内容をパースすべきです
		printf("%s", inbuf);

		// 相手が何を言おうとダミーHTTPメッセージ送信
		send(p->c_sock, buf, (int)strlen(buf), 0);

		closesocket(p->c_sock);
	}

	if (close_httpd(MAX) < 1) {
		return 0;
	}

	return 0;
}

