
// Pratice5_1View.h: CPratice51View 클래스의 인터페이스
//

#pragma once

enum DROW_MODE
{
	LINE_MODE,		//직선모드
	ELLIPSE_MODE,	//원그리기

};

class CPratice51View : public CView
{
protected: // serialization에서만 만들어집니다.
	CPratice51View() noexcept;
	DECLARE_DYNCREATE(CPratice51View)

// 특성입니다.
public:
	CPratice51Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CPratice51View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLine();
	int m_nDrawMode;

};

#ifndef _DEBUG  // Pratice5_1View.cpp의 디버그 버전
inline CPratice51Doc* CPratice51View::GetDocument() const
   { return reinterpret_cast<CPratice51Doc*>(m_pDocument); }
#endif

