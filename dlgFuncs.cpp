#include "Windows.h"
#include "resource.h"

INT_PTR CALLBACK newDialogProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);

    switch (msg)
    {
    case WM_INITDIALOG:
    {
        SYSTEMTIME time;
        GetLocalTime(&time);
        WCHAR strTime[200];
        wsprintf(strTime, L"Текущуее время : %d ч. %d мин. %d сек.",
            time.wHour, time.wMinute, time.wSecond);
        SetDlgItemText(hwndDlg, IDC_STATIC_TIME, strTime);
        SetFocus(GetDlgItem(hwndDlg, IDOK));
        return (INT_PTR)FALSE;
    }

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDOK:
            EndDialog(hwndDlg, wmId);
            return (INT_PTR)TRUE;
        case IDCANCEL:
            EndDialog(hwndDlg, wmId);
            return (INT_PTR)TRUE;
        default:
            break;
        }
        break;
    }

    default:
        return (INT_PTR)FALSE;
    }

    return (INT_PTR)FALSE;
}
