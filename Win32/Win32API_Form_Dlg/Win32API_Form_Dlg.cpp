// Win32API_Form_Dlg.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API_Form_Dlg.h"
#include <commdlg.h>
#include <stdio.h>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    DlgProc(HWND, UINT, WPARAM, LPARAM);

//폼기반 윈도우생성
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
    return 0;
}

//SetWindowText(HWND, 타이틀)      //폼 이름지정

//파일열기      #include <commdlg.h>포함
//파일관련정보담는 구조체
//OPENFILENAME.. 애 헤더파일에서 오류가나는데 이유를모르겠음
//lStructSize : 구조체의 크기  (sizeof(OPENFILENAME)하면됨)
//hWndOwner : 부모 윈도우 핸들넣기 hWnd
//lpstrFilter : 파일형식  ex) "비트맵(*.bmp)\0*.bmp\0".... \0연결하는느낌 *.bmp bmp파일만보이게
//nFileterIndex : 선택한 파일 인덱스 (1부터시작)
//lpstrFileTitle : 파일명 저장할 배열 설정 (static이나 전역변수로 지정해야함)
//nMaxFileTitle : 파일명을 저장할 배열의 길이
//lpstrFile : 전체경로를 저장할 배열 (static이나 전역변수로 지정해야함)
//lpstrTitle : 다이어로그 타이틀 문자열 지정

//파일저장
//

INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    WORD wmId = LOWORD(wParam);
    WORD wmEvent = HIWORD(wParam);

    OPENFILENAME ofn;
    //static이나 전역변수로 반드시 선언
    static char strFileTitle[MAX_PATH];   //파일제목.. 260
    static char strFile[100];             //파일명
    static char strFileExtension[10];     //파일확장자
    char str[100];

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        SetWindowText(hDlg, "Test_Title");
        wmId = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        switch (wmId)
        {
        case ID_32771:
            memset(&ofn, 0, sizeof(OPENFILENAME));      //이거 알아보기
            ofn.lStructSize = sizeof(OPENFILENAME);     //구조체크기설정
            ofn.lpstrTitle = "파일선택해";
            ofn.lpstrFile = strFile;    //파일명 입력받을 배열 전송
            ofn.lpstrFilter = "비트맵(*.bmp)\0*.bmp\0JPG파일(*.jpg)\0*.jpg\0";    //설명\0파일명 순서로 넣으면됨
            ofn.nMaxFile = MAX_PATH;        //파일경로최대길이설정
            ofn.nMaxFileTitle = MAX_PATH;   //파일제목최대길이설정
            if (GetOpenFileName(&ofn) != 0) //파일호출.. 0아니면 파일이 선택된것
            {
                switch (ofn.nFilterIndex)   //선택된 파일의 번호
                {
                case 1:     //1이면 bmp위에서지정
                    sprintf_s(strFileExtension, "선택한 파일 확장자 : %s", "bmp");
                    break;
                case 2:     //1이면 jpg위에서지정
                    sprintf_s(strFileExtension, "선택한 파일 확장자 : %s", "jpg");
                    break;
                }
                InvalidateRect(hDlg, NULL, true);
            }

        }
        break;

    case WM_PAINT:
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hDlg, &ps);

        sprintf_s(str, "%s", strFile);
        TextOut(hdc, 10, 10, str, strlen(str));
        sprintf_s(str, "%s", strFileTitle);
        TextOut(hdc, 10, 30, str, strlen(str));
        sprintf_s(str, "%s", strFileExtension);
        TextOut(hdc, 10, 50, str, strlen(str));

        EndPaint(hDlg, &ps);
    }
    return (INT_PTR)FALSE;
}
