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

    int y = 50;
    int lineSpacing = 20;
    SetTextColor(hdc, RGB(0, 0, 0));
    SetBkColor(hdc, RGB(255, 255, 255)); 

    for (const auto& line : g_lines)
    {
        TextOut(hdc, 50, y, line.c_str(), static_cast<int>(line.length()));
        y += lineSpacing;
    }

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
        if (ret == IDOK) wsprintf(result, L"������ ������ ��");
        if (ret == IDCANCEL) wsprintf(result, L"������ ������ ������");
        MessageBox(hwnd, result, TEXT(""), MB_OK);
        break;
    }
    case IDM_VIEW_CTL:
    {
        INT_PTR ret = DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_ELEMENT_CONTROL), hwnd, elementControlDialogProc);
        break;
    }
    case IDM_VIEW_TEXT:
    {
        INT_PTR ret = DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_TEXT), hwnd, viewTextDalogProc);
        break;
    }     
    case IDM_FILE_EXIT:
        MessageBox(hwnd, TEXT("������� ������� \"Exit\tAlt+x\""), TEXT("�����"), MB_OK);
        DestroyWindow(hwnd);
        break;
    case IDM_ABOUT:
        SendMessage(hwnd, WM_COMMAND, IDM_HELP_NEWDLG, 0);
        break;
    case IDM_EXIT:
        DestroyWindow(hwnd);
        break;
    default:
        TCHAR message[100];
        wsprintf(message, TEXT("������� � id %d �� �����������!"), id);
        MessageBox(hwnd, message, TEXT("��������������"), MB_OK);
        break;
    }
}