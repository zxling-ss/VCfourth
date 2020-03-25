
// MFCApplication53View.cpp: CMFCApplication53View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication53.h"
#endif

#include "MFCApplication53Doc.h"
#include "MFCApplication53View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication53View

IMPLEMENT_DYNCREATE(CMFCApplication53View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication53View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication53View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_32771, &CMFCApplication53View::On32771)
	ON_COMMAND(ID_32772, &CMFCApplication53View::On32772)
	ON_COMMAND(ID_32773, &CMFCApplication53View::On32773)
END_MESSAGE_MAP()

// CMFCApplication53View 构造/析构

CMFCApplication53View::CMFCApplication53View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication53View::~CMFCApplication53View()
{
}

BOOL CMFCApplication53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication53View 绘图

void CMFCApplication53View::OnDraw(CDC* pDC)
{
	CMFCApplication53Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->MoveTo(pDoc->p2);
	pDC->LineTo(pDoc->p3);
	pDC->Rectangle(pDoc->cr1);
	pDC->Ellipse(pDoc->cr2);
}


// CMFCApplication53View 打印


void CMFCApplication53View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication53View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication53View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication53View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication53View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication53View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication53View 诊断

#ifdef _DEBUG
void CMFCApplication53View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication53View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication53Doc* CMFCApplication53View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication53Doc)));
	return (CMFCApplication53Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication53View 消息处理程序


void CMFCApplication53View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication53Doc* pDoc = GetDocument();
	pDoc->p1.x = point.x;
	pDoc->p1.y = point.y;
	int temp = pDoc->p.x - pDoc->p1.x;
	int temp1 = pDoc->p.y - pDoc->p1.y;
	if (temp != 0 && temp != 0 && pDoc->a == 1) {
		pDoc->p2.x = pDoc->p.x; pDoc->p2.y = pDoc->p.y;
		pDoc->p3.x = pDoc->p1.x; pDoc->p3.y = pDoc->p1.y;
		Invalidate();
	}
	if (temp != 0 && temp1 != 0 && pDoc->b == 1) {
		pDoc->cr1.left = pDoc->p.x; pDoc->cr1.top = pDoc->p.y;
		pDoc->cr1.right= pDoc->p1.x; pDoc->cr1.bottom = pDoc->p1.y;
		Invalidate();
	}
	if (temp != 0 && temp1 != 0 && pDoc->c == 1) {
		pDoc->cr2.left = pDoc->p.x; pDoc->cr2.top = pDoc->p.y;
		pDoc->cr2.right = pDoc->p1.x; pDoc->cr2.bottom = pDoc->p1.y;
		Invalidate();
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication53View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication53Doc* pDoc = GetDocument();
	pDoc->p.x = point.x;
	pDoc->p.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication53View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication53Doc* pDoc = GetDocument();
	pDoc->a = 1;
}


void CMFCApplication53View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication53Doc* pDoc = GetDocument();
	pDoc->b = 1;
}


void CMFCApplication53View::On32773()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication53Doc* pDoc = GetDocument();
	pDoc->c= 1;
}
