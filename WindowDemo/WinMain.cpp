#include <Windows.h>
#include <iostream>
#include <string>
#include <stdlib.h>   
#include <tchar.h>   

#include "WinMain.h"
#include "WinMainKeyEvent.h"

using namespace std;

const char
	* APP_NAME_MAIN = "MainCls" ,		// ��������
	* APP_NAME = "WindowDemo"			// ��������
;		
/*------------------
��������ڵ�
-------------------*/
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR lpcmdline, int cmdShow) {
	// ������������
	HWND hWnd;			// ��������
	MSG msg;				// ������Ϣ��
	// ���������ࡣ
	WNDCLASS WinMain_Class;
	//WinMain_Class.cbSize						= sizeof(WNDCLASSEX);												// ���д��д������ν������Ҫȷ�����ֱ�Ӱѽṹ�嶪��ȥ��һ��Ҫд����Ϊû��Ĭ��ֵ��
	WinMain_Class.style						= CS_CLASSDC | CS_VREDRAW | CS_HREDRAW;			// �ػ�ȷ�����岻������
	WinMain_Class.cbClsExtra				= 0;																					// ��ʼ�� WNDCLASS ���ڴ�Ϊ0��
	WinMain_Class.cbWndExtra			= 0;																					// ��ʼ�� WNDCLASS �����ڴ�Ϊ0��
	WinMain_Class.hInstance				= hinstance;																		// �󶨳��������󶨱�����ʵ����			
	WinMain_Class.hIcon						= NULL;																			// ͼ�ꡣ
	WinMain_Class.hCursor					= NULL;																			// ���ָ�롣
	WinMain_Class.hbrBackground		= CreateSolidBrush(RGB(222, 222, 222));						// ����ˢ��
	WinMain_Class.lpszMenuName		= NULL;																			// �˵�����ûɶ�á�
	WinMain_Class.lpfnWndProc			= WndProc;																		// ��ʼ��������Ϣ�ĺ���ָ�롣
	WinMain_Class.lpszClassName		= APP_NAME_MAIN;														// ����������
	// ע�ᴰ���ࡣ
	const int isSuccessRegCls = RegisterClass(&WinMain_Class);
	if (!isSuccessRegCls) {
		MessageBox(NULL, TEXT("Unable to register window class."), APP_NAME_MAIN, MB_ICONERROR);
		return QUIT_MAINWINDOW_REGISTER_FAIL;
	}
	// �������塣
	const UINT
		scWidth			= GetSystemMetrics(SM_CXSCREEN),
		scHeight			= GetSystemMetrics(SM_CYSCREEN),		/* ��ȡ����Ļ�ֱ��ʡ� */
		wndWidth		= 800,
		wndHeight		= 600														/* ���ó�����Դ�С�� */
		;	
	hWnd = CreateWindow(
		APP_NAME_MAIN,							// ������������
		APP_NAME,										// ������⡣
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX& ~WS_THICKFRAME,
		(scWidth - wndWidth) / 2,				// ��ʼ������ĻX�ᡣ
		(scHeight - wndHeight) / 2,				// ��ʼ������ĻY�ᡣ
		wndWidth,										// �����ȡ�
		wndHeight,										// ����߶ȡ�
		NULL,												// ����������
		NULL,												// ����˵������ûɶ�á�
		hinstance,										// ������/ʵ����
		NULL												// ����������ûɶ�á�������Ǵ��崴������Ϣ��WM_CREATE�Ĳ�����
	);
	// ��ʾ����
	ShowWindow(hWnd, cmdShow);		
	UpdateWindow(hWnd);						// ���� WM_PAINT ��Ϣ����ʵֻ��ȷ�������״λ���������ʵ�������á�
	// ��Ϣѭ��
	while (GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);				// ������Ϣ�����Ѿ����͵���Ϣ���У�
		DispatchMessage(&msg);				// ������Ϣ��
	}
	return 0;
}

/*------------------
��������Ϣ
-------------------*/
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM W_Param, LPARAM L_Param) {
	switch (msg)
	{
	case WM_DESTROY:					/* ���������١� */
		PostQuitMessage(W_Param);				// �˳�����
		return 0;
	case WM_KEYDOWN:					/* ���������¡� */
		Main_KeyDown(hWnd, W_Param);
		return 0;
	case WM_PAINT:
		return 0;
	}
	// ��û���յ���Ϣ��ʱ�򷵻�Ĭ����Ϣ��
	return DefWindowProcA(hWnd, msg, W_Param, L_Param);
}