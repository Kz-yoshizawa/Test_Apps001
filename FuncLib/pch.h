// pch.h: プリコンパイル済みヘッダー ファイルです。
// 次のファイルは、その後のビルドのビルド パフォーマンスを向上させるため 1 回だけコンパイルされます。
// コード補完や多くのコード参照機能などの IntelliSense パフォーマンスにも影響します。
// ただし、ここに一覧表示されているファイルは、ビルド間でいずれかが更新されると、すべてが再コンパイルされます。
// 頻繁に更新するファイルをここに追加しないでください。追加すると、パフォーマンス上の利点がなくなります。

#ifndef PCH_H
#define PCH_H

// プリコンパイルするヘッダーをここに追加します
#include "framework.h"
#include <stdio.h>

typedef int int32_t;
typedef char int8_t;

/* わかりやすいようにtypedefして使う */
typedef int8_t(*p_func_type)(int32_t);

int32_t	func1(void);
void func_task(p_func_type, int32_t, int8_t*);
int8_t func_callback1(int32_t);
int8_t func_callback2(int32_t);
int8_t func_callback3(int32_t);

typedef struct t_func{
	p_func_type		fp;
	unsigned int	primary;
}T_FUNC;

#endif //PCH_H
