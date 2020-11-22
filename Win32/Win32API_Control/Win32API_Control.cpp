

// Win32API_Control.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API_Control.h"
#include <string.h>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    DlgProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);

    return 0;
}

//컨트롤 (=하나의 작은윈도우)
//생성 : CreateWindow()
//컨트롤아이디 : 중복되지않는 양의정수값 (IDC_값 으로 자동으로 지정됨)
//윈도우핸들 : HWND GetDlgItem(HWND 다이어로그핸들, int 컨트롤아이디)
//컨트롤 메시지 처리 : WM_COMMAND발생
//LOWORD(wParam) : 컨트롤 아이디값
//HIWORD(lParam) : 컨트롤 상태(통지코드)
//
//Static Text
//button

//radio
//UINT IsDlgButtonChecked(HWND, int 라디오버튼아이디)
//반환값(상태) : BST_CHECKED, BST_UNCHECKED
//BOOL CheckDlgButton(HWND, int 라디오버튼아이디, UINT 체크유무)
//체크유무 : BST_UNCHECKED/CHECKED
//BOOL CheckedRadioButton(HWND, int 시작ID, int 끝ID, int 체크할라디오버튼아이디) //체크만가능

//checkBox도 라디오버튼과 같이 밑에꺼두개 사용
//IsDlgButtonChecked
//CheckDlgButton

INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    int radioID[4]{ IDC_RADIO_red, IDC_RADIO_blue, IDC_RADIO_green, IDC_RADIO_purple };
    int checkboxID[3]{ IDC_CHECK_first, IDC_CHECK_second, IDC_CHECK_third};
    char radioString[100]{ '\0' };
    char checkBoxString[100]{ '\0' };

    switch (message)
    {
    case WM_CLOSE:
        EndDialog(hDlg, LOWORD(wParam));
        return (INT_PTR)TRUE;

    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hDlg, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hDlg, &ps);
    }
    break;

    case WM_COMMAND:
        switch (LOWORD(wParam)) //컨트롤아이디값을 switch~case로 구별
        {
        //======================라디오버튼=============================
        case IDC_BUTTON_push:   //push버튼누르면실행
            for (int i = 0; i < 4; i++)
            {
                if (IsDlgButtonChecked(hDlg, radioID[i]) == BST_CHECKED)
                {
                    switch (i)
                    {
                    case 0:
                        strcpy_s(radioString, "red");
                        break;
                    case 1:
                        strcpy_s(radioString, "blue");
                        break;
                    case 2:
                        strcpy_s(radioString, "green");
                        break;
                    case 3:
                        strcpy_s(radioString, "purple");
                        break;
                    }
                }  
            }
            MessageBox(NULL, radioString, "push click", MB_OK);
            break;
        case IDC_BUTTON_checkDlgButton:    //라디오버튼중복체크/해제하기
            CheckDlgButton(hDlg, IDC_RADIO_purple, BST_CHECKED);
            break;
        case IDC_BUTTON_CheckRadioButton:    //라디오버튼체크하기
            CheckRadioButton(hDlg, IDC_RADIO_red, IDC_RADIO_purple, IDC_RADIO_green);
            break;

        //======================체크박스=============================
            //체크박스 누를때마다 실행
        case IDC_CHECK_first:
            MessageBox(NULL, "first_check", "checkBox", MB_OK);
            break;
        case IDC_CHECK_second:
            MessageBox(NULL, "second_check", "checkBox", MB_OK);
            break;
        case IDC_CHECK_third:
            MessageBox(NULL, "third_check", "checkBox", MB_OK);
            break;
        case IDC_BUTTON_IsDlgButton:   //IsDlgButton버튼누르면
            for (int i = 0; i < 3; i++)
            {
                if (IsDlgButtonChecked(hDlg, checkboxID[i]) == BST_CHECKED)
                {
                    switch (i)
                    {
                    case 0:
                        strcat_s(radioString, sizeof(radioString), "first ");
                        break;
                    case 1:
                        strcat_s(radioString, sizeof(radioString), "second ");
                        break;
                    case 2:
                        strcat_s(radioString, sizeof(radioString), "third");
                        break;
                    }
                }
            }
            MessageBox(NULL, radioString, "push click", MB_OK);
            break;
        case IDC_BUTTON_checkDlgButton2:    //체크박스 체크/해제하기
            CheckDlgButton(hDlg, IDC_CHECK_third, BST_CHECKED);
            break;
        }
        break;
    }
    return (INT_PTR)FALSE;
}