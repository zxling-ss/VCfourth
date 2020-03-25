
// MFCApplication52View.cpp: CMFCApplication52View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication52.h"
#endif

#include "MFCApplication52Doc.h"
#include "MFCApplication52View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication52View

IMPLEMENT_DYNCREATE(CMFCApplication52View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication52View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication52View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication52View 构造/析构

CMFCApplication52View::CMFCApplication52View() noexcept
{
	// TODO: 在此处添加构造代码
	
	BITMAP BM;
	m.LoadBitmapW(IDB_BITMAP1);
	m.GetBitmap(&BM);
	m_nwidth = BM.bmWidth;
	m_nhight = BM.bmHeight;
}

CMFCApplication52View::~CMFCApplication52View()
{
}

BOOL CMFCApplication52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication52View 绘图

void CMFCApplication52View::OnDraw(CDC* pDC)
{
	CMFCApplication52Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m);
	pDC->BitBlt(0, 0, m_nwidth, m_nhight, &MemDC, 0, 0, SRCCOPY);
}


// CMFCApplication52View 打印


void CMFCApplication52View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication52View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication52View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication52View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication52View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication52View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication52View 诊断

#ifdef _DEBUG
void CMFCApplication52View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication52View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication52Doc* CMFCApplication52View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication52Doc)));
	return (CMFCApplication52Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication52View 消息处理程序
