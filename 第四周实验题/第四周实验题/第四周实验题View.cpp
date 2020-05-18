
// 第四周实验题View.cpp : C第四周实验题View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第四周实验题.h"
#endif

#include "第四周实验题Doc.h"
#include "第四周实验题View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第四周实验题View

IMPLEMENT_DYNCREATE(C第四周实验题View, CView)

BEGIN_MESSAGE_MAP(C第四周实验题View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C第四周实验题View 构造/析构

C第四周实验题View::C第四周实验题View()
{
	// TODO: 在此处添加构造代码
	count = 0;

	up = 0; 
	down = 0;
	right = 0; 
	left=0;

}

C第四周实验题View::~C第四周实验题View()
{
}

BOOL C第四周实验题View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第四周实验题View 绘制

void C第四周实验题View::OnDraw(CDC*  pDC)
{
	C第四周实验题Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	//(2) 在窗口客户区中间绘制一个矩形，按键盘上的四个方向键可以使矩形向相应方向移动，
	//按Home键使矩形向左上角方向增大，按End键时矩形向右下角缩小，当单击鼠标左键时，矩形恢复到原来大小。
	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(0, 0, 0));
	
	if (VK_UP) {
		up+=10;
		pDC->Rectangle(200, 200+up, 400, 400+up);
	}
		

}


// C第四周实验题View 打印

BOOL C第四周实验题View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第四周实验题View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第四周实验题View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第四周实验题View 诊断

#ifdef _DEBUG
void C第四周实验题View::AssertValid() const
{
	CView::AssertValid();
}

void C第四周实验题View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第四周实验题Doc* C第四周实验题View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第四周实验题Doc)));
	return (C第四周实验题Doc*)m_pDocument;
}
#endif //_DEBUG


// C第四周实验题View 消息处理程序

//对于鼠标左键按下
void C第四周实验题View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	count =	0;
	x1 = point.x;

	CView::OnLButtonDown(nFlags, point);
}

///鼠标移动统计
void C第四周实验题View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	count++;

	CView::OnMouseMove(nFlags, point);
}


//鼠标抬起
void C第四周实验题View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	x2 = point.x;
	if(count!=0)
		s.Format(_T("MouseMove发生:%d 次,每次横向移动：%d 像素点"),count,(abs(x2-x1)/count));
	else
		s.Format(_T("MouseMove发生:%d 次,每次横向移动：%d 像素点"), count,0);
	dc.TextOutW(100, 100, s);

	CView::OnLButtonUp(nFlags, point);
}
