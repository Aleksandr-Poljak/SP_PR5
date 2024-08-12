#include "resource.h"
#include "wndProcFuncs.h"
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
    case IDM_HELP_NEWDLG:
    {
        INT_PTR ret = DialogBox(hInst, MAKEINTRESOURCE(IDD_NEW_DIALOG), hwnd, newDialogProc);
        wchar_t result[200] = L"\0";
        if (ret == IDOK) wsprintf(result, L"Нажата кнопка ОК");
        if (ret == IDCANCEL) wsprintf(result, L"Нажата кнопка Отмена");
        MessageBox(hwnd, result, TEXT(""), MB_OK);
        break;
    }
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
        SendMessage(hwnd, WM_COMMAND, IDM_HELP_NEWDLG, 0);
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