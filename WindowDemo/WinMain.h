#pragma once
#include <Windows.h>

#define QUIT_NORMAL											0x1					// �����˳�
#define QUIT_MAINWINDOW_REGISTER_FAIL		0x2					// ������ע��ʧ��

LRESULT WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);							// ��Ϣ�ص���
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);									// ������������ڵ㡣


