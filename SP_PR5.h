#ifndef SP_PR5_H
#define SP_PR5_H

#include "resource.h"

#define MAX_LOADSTRING 100

// ���������� ���������� ����������
extern HINSTANCE hInst;                                // ������� ���������
extern WCHAR szTitle[MAX_LOADSTRING];                  // ����� ������ ���������
extern WCHAR szWindowClass[MAX_LOADSTRING];            // ��� ������ �������� ����
extern MSG msg;

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

#endif // SP_PR5_H