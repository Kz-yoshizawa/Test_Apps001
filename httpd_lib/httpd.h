// pch.h: プリコンパイル済みヘッダー ファイルです。
// 次のファイルは、その後のビルドのビルド パフォーマンスを向上させるため 1 回だけコンパイルされます。
// コード補完や多くのコード参照機能などの IntelliSense パフォーマンスにも影響します。
// ただし、ここに一覧表示されているファイルは、ビルド間でいずれかが更新されると、すべてが再コンパイルされます。
// 頻繁に更新するファイルをここに追加しないでください。追加すると、パフォーマンス上の利点がなくなります。


#ifndef _HTTPD_H_
#define _HTTPD_H_

#define WIN32_LEAN_AND_MEAN   

// Winsock
#include <winsock2.h>

typedef struct t_http_client {

	SOCKET				sock;
	struct sockaddr_in	client_addr;
	int					len;

} T_HTTP_CLIENT;

typedef struct t_http_server {

	SOCKET				sock;
	struct sockaddr_in	server_addr;

} T_HTTP_SERVER;


void init_winsock();


#endif //_HTTPD_H_
