// Win32API_Control2.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API_Control2.h"
#include <stdio.h>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

INT_PTR CALLBACK    DlgProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);

    return 0;
}

/*
* Edit Control데이터 읽기
* UInt GetDlgItemText(HWND, int 에디트박스아이디, LPCSTR 입력받을 문자열주소, int 문자열최대길이)
* UInt GetDlgItemInt(HWND, int 에디트박스아이디, BOOL* NULL, BOOL true(+-)/false(+))
* 
* Edit Control데이터 쓰기
* BOOL SetDlgItemText(HWND, int 에디트박스아이디, LPCSTR 입력할 문자열주소)
* BOOL SetDlgItemInt(HWND, int 에디트박스아이디, int 입력할정수, BOOL true(+-)/false(+))
*/
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    char str[100];
    int number = 0;

    switch (message)
    {
    case WM_CLOSE:
        EndDialog(hDlg, LOWORD(wParam));
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
        case IDC_BUTTON_GetDlgItemText:
            GetDlgItemText(hDlg, IDC_EDIT_input, str, 100);
            MessageBox(hDlg, str, "GetDlgItemText", MB_OK);
            break;
        case IDC_BUTTON_GetDlgItemInt:
            number = GetDlgItemInt(hDlg, IDC_EDIT_input, NULL, true);
            sprintf_s(str, "%d", number);
            MessageBox(hDlg, str, "GetDlgItemInt", MB_OK);
            break;

        case IDC_BUTTON_SetDlgItemText:
            SetDlgItemText(hDlg, IDC_EDIT_output, "SetDlgItemText()");
            break;
        case IDC_BUTTON_SetDlgItemInt:
            SetDlgItemInt(hDlg, IDC_EDIT_output, -13, true);
            break;
        }
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hDlg, &ps);



            EndPaint(hDlg, &ps);
        }
        break;
    }


    return (INT_PTR)FALSE;
}
