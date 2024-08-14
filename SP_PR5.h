#ifndef SP_PR5_H
#define SP_PR5_H

#include "resource.h"
#include <vector>
#include <string>

#define MAX_LOADSTRING 100

// Объявление глобальных переменных
extern HINSTANCE hInst;                                // текущий экземпляр
extern WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
extern WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
extern MSG msg;
extern std::vector<std::wstring> g_lines;              // Хранения вектора строк

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

/// <summary>
/// Процедура диалога New Dialog.
/// </summary>
/// <param name="hwndDlg">дескриптор диалогового окна</param>
/// <param name="msg">код сообщения</param>
/// <param name="wParam">первый параметр сообщения</param>
/// <param name="lParam">второй параметр сообщения</param>
/// <returns></returns>
INT_PTR CALLBACK newDialogProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);

/// <summary>
/// Процедура диалога Элементы управления.
/// Позволяет вводить и сохранять текст.
/// </summary>
INT_PTR CALLBACK elementControlDialogProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);

#endif // SP_PR5_H