#pragma once
#include <Windows.h>

#define QUIT_NORMAL											0x1					// 正常退出
#define QUIT_MAINWINDOW_REGISTER_FAIL		0x2					// 主窗体注册失败

LRESULT WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);							// 消息回调。
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);									// 窗体主函数入口点。


