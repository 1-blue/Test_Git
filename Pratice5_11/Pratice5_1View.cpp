
// Pratice5_1View.cpp: CPratice51View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Pratice5_1.h"
#endif

#include "Pratice5_1Doc.h"
#include "Pratice5_1View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPratice51View

IMPLEMENT_DYNCREATE(CPratice51View, CView)

BEGIN_MESSAGE_MAP(CPratice51View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_line, &CPratice51View::OnLine)
END_MESSAGE_MAP()

// CPratice51View 생성/소멸

CPratice51View::CPratice51View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPratice51View::~CPratice51View()
{
}

BOOL CPratice51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPratice51View 그리기

void CPratice51View::OnDraw(CDC* /*pDC*/)
{
	CPratice51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CPratice51View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPratice51View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPratice51View 진단

#ifdef _DEBUG
void CPratice51View::AssertValid() const
{
	CView::AssertValid();
}

void CPratice51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPratice51Doc* CPratice51View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPratice51Doc)));
	return (CPratice51Doc*)m_pDocument;
}
#endif //_DEBUG


// CPratice51View 메시지 처리기

//직선그리기클릭했을때 실행할 함수
void CPratice51View::OnLine()
{
	m_nDrawMode = LINE_MODE;	//직선모드 = LINE_MODE로 지정

	//그릴위치의 포인터 얻기

	//실행되는지 테스트
	AfxMessageBox(_T("직선 그리기 모드 실행..."));

	//상태바에 그리기모드 정보 출력 MainFrame사용
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();			//MainWindow의 포인터값 얻어오기
	pFrame->m_wndStatusBar.SetWindowTextW(_T("직선그리기"));		//스테이터스바에 직선그리기출력





}
