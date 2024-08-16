#ifndef SP_PR5_H
#define SP_PR5_H

#include "resource.h"
#include <vector>
#include <string>

#define MAX_LOADSTRING 100
#define MAX_BYTES  1024
#define WM_USER_UPDATE_TEXT (WM_USER +1)

// ���������� ���������� ����������
extern HINSTANCE hInst;                                // ������� ���������
extern WCHAR szTitle[MAX_LOADSTRING];                  // ����� ������ ���������
extern WCHAR szWindowClass[MAX_LOADSTRING];            // ��� ������ �������� ����
extern MSG msg;
extern std::vector<std::wstring> g_lines;              // �������� ������� �����
extern char Buffer[MAX_BYTES];						   // �������� ����������� ������
extern char InitialBuffer[MAX_BYTES];                 // ��� ��������� ����. ������

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

/// <summary>
/// ��������� ������� New Dialog.
/// </summary>
/// <param name="hwndDlg">���������� ����������� ����</param>
/// <param name="msg">��� ���������</param>
/// <param name="wParam">������ �������� ���������</param>
/// <param name="lParam">������ �������� ���������</param>
/// <returns></returns>
INT_PTR CALLBACK newDialogProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);

/// <summary>
/// ��������� ������� �������� ����������.
/// ��������� ������� � ��������� �����.
/// </summary>
INT_PTR CALLBACK elementControlDialogProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);

/// <summary>
/// ��������� ������� �����.
/// ��������� ����� ��� ����������� ������ � ���������.
/// </summary>
/// <param name="hwndDlg"></param>
/// <param name="msg"></param>
/// <param name="wParam"></param>
/// <param name="lParam"></param>
/// <returns></returns>
INT_PTR CALLBACK viewTextDalogProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);

#endif // SP_PR5_H