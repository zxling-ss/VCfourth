
// MFCApplication51View.cpp: CMFCApplication51View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication51.h"
#endif

#include "MFCApplication51Doc.h"
#include "MFCApplication51View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication51View

IMPLEMENT_DYNCREATE(CMFCApplication51View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication51View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication51View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CMFCApplication51View::On32771)
END_MESSAGE_MAP()

// CMFCApplication51View 构造/析构

CMFCApplication51View::CMFCApplication51View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication51View::~CMFCApplication51View()
{
}

BOOL CMFCApplication51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication51View 绘图

void CMFCApplication51View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication51View 打印


void CMFCApplication51View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication51View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication51View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication51View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication51View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication51View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication51View 诊断

#ifdef _DEBUG
void CMFCApplication51View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication51Doc* CMFCApplication51View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication51Doc)));
	return (CMFCApplication51Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication51View 消息处理程序


void CMFCApplication51View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("张晓灵");
	CClientDC dc(this);
	dc.TextOutW(200, 400, s);
}
