// ConsoleApps_main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include "httpd.h"

#pragma comment(lib, "httpd_lib.lib")

extern int httpd_main(void);

int main()
{
    printf("Hello World!\n");

	////p_func_type		p_func;
	//int8_t			rc;
	//int		arry = 0;
	//int		str = 0;
	//int		num = 0;

	//T_FUNC	pt[] = {
	//	{func_callback1, PRIMARY_HIGH},
	//	{func_callback2, PRIMARY_MID},
	//	{func_callback3, PRIMARY_LOW}
	//};

	//arry = sizeof(pt);
	//str = sizeof(T_FUNC);
	//num = arry / str;

	//for (int i = 0; i < num; i++) {
	//	func_task(pt[i].fp, 10, &rc);
	//}

	if (!httpd_main()) {
		return 0;
	}

	return (0);
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
