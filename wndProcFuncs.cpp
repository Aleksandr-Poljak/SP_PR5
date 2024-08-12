#include "wndProcFuncs.h"
#include "resource.h"
#include "SP_PR5.h"

void wndProc_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) 
{

}

void wndProc_OnDestroy(HWND hwnd)
{
    PostQuitMessage(0);
}

void wndProc_OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    EndPaint(hwnd, &ps);
}

void wndProc_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{

    switch (id)
    {
    case IDM_FILE_EXIT:
        MessageBox(hwnd, TEXT("Выбрана команда \"Exit\tAlt+x\""), TEXT("Выход"), MB_OK);
        DestroyWindow(hwnd);
        break;
    case IDM_VIEW_TEXT:
        MessageBox(hwnd, TEXT("Выбрана команда \"ТЕКСТ\""), TEXT("ТЕКСТ"), MB_OK);
        break;
    case IDM_VIEW_CTL:
        MessageBox(hwnd, TEXT("Выбрана команда \"Элементы управления\""), TEXT("ТЕКСТ"), MB_OK);
        break;
    case IDM_ABOUT:
        MessageBox(hwnd, TEXT("Выбрана команда \"About\""),TEXT("IDM_ABOUT"), MB_OK);
        DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hwnd, About);
        break;
    case IDM_EXIT:
        DestroyWindow(hwnd);
        break;
    default:
        TCHAR message[100];
        wsprintf(message, TEXT("Команда с id %d не реализована!"), id);
        MessageBox(hwnd, message, TEXT("Предупреждение"), MB_OK);
        break;
    }
}