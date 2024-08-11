#ifndef SP_PR5_H
#define SP_PR5_H

#include "resource.h"

#define MAX_LOADSTRING 100

// ќбъ€вление глобальных переменных
extern HINSTANCE hInst;                                // текущий экземпл€р
extern WCHAR szTitle[MAX_LOADSTRING];                  // “екст строки заголовка
extern WCHAR szWindowClass[MAX_LOADSTRING];            // им€ класса главного окна
extern MSG msg;

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

#endif // SP_PR5_H