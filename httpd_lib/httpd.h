// pch.h: プリコンパイル済みヘッダー ファイルです。
// 次のファイルは、その後のビルドのビルド パフォーマンスを向上させるため 1 回だけコンパイルされます。
// コード補完や多くのコード参照機能などの IntelliSense パフォーマンスにも影響します。
// ただし、ここに一覧表示されているファイルは、ビルド間でいずれかが更新されると、すべてが再コンパイルされます。
// 頻繁に更新するファイルをここに追加しないでください。追加すると、パフォーマンス上の利点がなくなります。


#ifndef _HTTPD_H_
#define _HTTPD_H_

#include <stdio.h>
#include <stdlib.h>
// Winsock
#include <winsock2.h>

typedef unsigned int SOCKETID;

typedef int(*p_httpd_func_type)(void);

typedef struct t_http_socket {

	WSADATA					wsaData;
	SOCKET					s_sock;
	struct sockaddr_in		client_addr;
	int						len;
	SOCKET					c_sock;
	struct sockaddr_in		server_addr;
	SOCKETID				sid;
	BOOL					yes;
	struct t_http_socket*	p;

} T_HTTP_SOCKET;

int		en_queue(int);
int		de_queue();
T_HTTP_SOCKET*	take_queue(SOCKETID);
int		init_httpd(int);
int		close_httpd(int);
int		httpd_main(void);


#endif //_HTTPD_H_
