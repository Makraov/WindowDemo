#include <Windows.h>
#include <iostream>
#include <string>
#include <stdlib.h>   
#include <tchar.h>   

#include "WinMain.h"
#include "WinMainKeyEvent.h"

using namespace std;

const char
	* APP_NAME_MAIN = "MainCls" ,		// 主类名。
	* APP_NAME = "WindowDemo"			// 程序名。
;		
/*------------------
主程序入口点
-------------------*/
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR lpcmdline, int cmdShow) {
	// 创建窗体句柄。
	HWND hWnd;			// 窗体句柄。
	MSG msg;				// 窗体消息。
	// 创建窗体类。
	WNDCLASS WinMain_Class;
	//WinMain_Class.cbSize						= sizeof(WNDCLASSEX);												// 这个写不写都无所谓，但是要确认如果直接把结构体丢进去就一定要写，因为没有默认值。
	WinMain_Class.style						= CS_CLASSDC | CS_VREDRAW | CS_HREDRAW;			// 重绘确保窗体不会闪。
	WinMain_Class.cbClsExtra				= 0;																					// 初始化 WNDCLASS 类内存为0。
	WinMain_Class.cbWndExtra			= 0;																					// 初始化 WNDCLASS 窗体内存为0。
	WinMain_Class.hInstance				= hinstance;																		// 绑定程序句柄，绑定本程序实例。			
	WinMain_Class.hIcon						= NULL;																			// 图标。
	WinMain_Class.hCursor					= NULL;																			// 鼠标指针。
	WinMain_Class.hbrBackground		= CreateSolidBrush(RGB(222, 222, 222));						// 背景刷。
	WinMain_Class.lpszMenuName		= NULL;																			// 菜单名，没啥用。
	WinMain_Class.lpfnWndProc			= WndProc;																		// 初始化接收消息的函数指针。
	WinMain_Class.lpszClassName		= APP_NAME_MAIN;														// 窗体类名。
	// 注册窗体类。
	const int isSuccessRegCls = RegisterClass(&WinMain_Class);
	if (!isSuccessRegCls) {
		MessageBox(NULL, TEXT("Unable to register window class."), APP_NAME_MAIN, MB_ICONERROR);
		return QUIT_MAINWINDOW_REGISTER_FAIL;
	}
	// 创建窗体。
	const UINT
		scWidth			= GetSystemMetrics(SM_CXSCREEN),
		scHeight			= GetSystemMetrics(SM_CYSCREEN),		/* 获取主屏幕分辨率。 */
		wndWidth		= 800,
		wndHeight		= 600														/* 设置程序绝对大小。 */
		;	
	hWnd = CreateWindow(
		APP_NAME_MAIN,							// 窗体主类名。
		APP_NAME,										// 窗体标题。
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX& ~WS_THICKFRAME,
		(scWidth - wndWidth) / 2,				// 初始化主屏幕X轴。
		(scHeight - wndHeight) / 2,				// 初始化主屏幕Y轴。
		wndWidth,										// 窗体宽度。
		wndHeight,										// 窗体高度。
		NULL,												// 父窗体句柄。
		NULL,												// 窗体菜单句柄，没啥用。
		hinstance,										// 程序句柄/实例。
		NULL												// 创建参数，没啥用。（这个是窗体创建的消息给WM_CREATE的参数）
	);
	// 显示窗体
	ShowWindow(hWnd, cmdShow);		
	UpdateWindow(hWnd);						// 发送 WM_PAINT 消息，其实只是确保窗体首次绘制正常，实则并无卵用。
	// 消息循环
	while (GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);				// 翻译消息。（已经发送到消息队列）
		DispatchMessage(&msg);				// 接收消息。
	}
	return 0;
}

/*------------------
主程序消息
-------------------*/
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM W_Param, LPARAM L_Param) {
	switch (msg)
	{
	case WM_DESTROY:					/* 当窗体销毁。 */
		PostQuitMessage(W_Param);				// 退出程序。
		return 0;
	case WM_KEYDOWN:					/* 当按键按下。 */
		Main_KeyDown(hWnd, W_Param);
		return 0;
	case WM_PAINT:
		return 0;
	}
	// 当没有收到信息的时候返回默认消息。
	return DefWindowProcA(hWnd, msg, W_Param, L_Param);
}