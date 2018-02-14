#include "WinMainKeyEvent.h"

void Main_KeyDown(HWND hWnd,WPARAM keyCode) {
	switch (keyCode){
	case VK_ESCAPE:
		Main_KeyDown_Escape(hWnd);
		return;
	}
}

void Main_KeyDown_Escape(HWND hWnd) {
	SendMessage(hWnd, WM_DESTROY, 0, 0);
}