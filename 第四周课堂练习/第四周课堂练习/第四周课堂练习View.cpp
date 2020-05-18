
// 第四周课堂练习View.cpp : C第四周课堂练习View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第四周课堂练习.h"
#endif

#include "第四周课堂练习Doc.h"
#include "第四周课堂练习View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第四周课堂练习View

IMPLEMENT_DYNCREATE(C第四周课堂练习View, CView)

BEGIN_MESSAGE_MAP(C第四周课堂练习View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C第四周课堂练习View 构造/析构

C第四周课堂练习View::C第四周课堂练习View()
{
	// TODO: 在此处添加构造代码

}

C第四周课堂练习View::~C第四周课堂练习View()
{
}

BOOL C第四周课堂练习View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第四周课堂练习View 绘制

void C第四周课堂练习View::OnDraw(CDC* pDC)
{
	C第四周课堂练习Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec);

	
}


// C第四周课堂练习View 打印

BOOL C第四周课堂练习View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第四周课堂练习View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第四周课堂练习View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第四周课堂练习View 诊断

#ifdef _DEBUG
void C第四周课堂练习View::AssertValid() const
{
	CView::AssertValid();
}

void C第四周课堂练习View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第四周课堂练习Doc* C第四周课堂练习View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第四周课堂练习Doc)));
	return (C第四周课堂练习Doc*)m_pDocument;
}
#endif //_DEBUG


// C第四周课堂练习View 消息处理程序

//且在鼠标移动过程中在客户区显示鼠标的位置信息
void C第四周课堂练习View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC clientDC(this);
	CString s;
	s.Format(_T("鼠标坐标：%d,%d"),point.x,point.y);
	clientDC.TextOutW(20, 20, s);



	CView::OnMouseMove(nFlags, point);
}

//对于鼠标左键按下，移动直到抬起的这个过程，在按下时记录下鼠标位置,
void C第四周课堂练习View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	C第四周课堂练习Doc* pDoc = GetDocument();
	pDoc->m_tagRec.right = point.x;
	pDoc->m_tagRec.top= point.y;


	CView::OnLButtonDown(nFlags, point);
}

// 对于鼠标左键按下，移动直到抬起的这个过程，在按下时记录下鼠标位置,　抬起画出一个矩形，以按下和抬起的位置作为矩形的两对角。

void C第四周课堂练习View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第四周课堂练习Doc* pDoc = GetDocument();
	pDoc->m_tagRec.left = point.x;
	pDoc->m_tagRec.bottom = point.y;

	//强制重绘
	InvalidateRect(NULL, TRUE);

	CView::OnLButtonUp(nFlags, point);
}
