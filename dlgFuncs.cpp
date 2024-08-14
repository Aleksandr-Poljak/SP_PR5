#include "Windows.h"
#include "resource.h"
#include "SP_PR5.h"
#include <tchar.h>
#include <string>
#include <vector>

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

INT_PTR CALLBACK elementControlDialogProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    static HWND hEdit, hList;
    static TCHAR str[300] = { 0 };

    switch (msg)
    {
    case WM_INITDIALOG:
    {
        hEdit = GetDlgItem(hwndDlg, IDC_EDIT_TEXT);
        hList = GetDlgItem(hwndDlg, IDC_LIST_TEXT);
        return (INT_PTR)TRUE;
    }
    case WM_COMMAND:
    {
        int id = LOWORD(wParam);
        switch (id)
        {
        case IDC_BUTTON_READ:
            memset(str, 0, sizeof(str));
            GetDlgItemText(hwndDlg, IDC_EDIT_TEXT, str, sizeof(str) / sizeof(TCHAR));
            MessageBox(hwndDlg, str, L"Прочитано в буфер", MB_OK);
            SetDlgItemText(hwndDlg, IDC_EDIT_TEXT, L"");
            SetFocus(hEdit);
            break;
        case IDC_BUTTON_ADD:
            if (_tcslen(str) == 0)
            {
                MessageBox(hwndDlg, L"Буфер пуст, ничего не добавлено.", L"Ошибка", MB_OK);
            }
            else
            {
                SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)str);
                MessageBox(hwndDlg, str, L"Добавлено в ListBox", MB_OK);
                memset(str, 0, sizeof(str));
            }
            SetFocus(hEdit);
            return (INT_PTR)TRUE;
            break;
        case IDOK:
        {
            int count = SendMessage(hList, LB_GETCOUNT, 0, 0);
            std::vector<std::wstring> lines;
            TCHAR buffer[300] = { 0 };

            for (int i = 0; i < count; i++)
            {
                SendMessage(hList, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
                lines.push_back(buffer);
            }

            SendMessage(GetParent(hwndDlg), WM_USER_UPDATE_TEXT, (WPARAM)&lines, 0);
            memset(str, 0, sizeof(str));
            EndDialog(hwndDlg, 0);
            return (INT_PTR)TRUE;
            break;
        }
        case IDCANCEL:
            memset(str, 0, sizeof(str));
            EndDialog(hwndDlg, 0);
            return (INT_PTR)TRUE;
            break;
        default:
            break;
        }
    }
    }

    return (INT_PTR)FALSE;
}
