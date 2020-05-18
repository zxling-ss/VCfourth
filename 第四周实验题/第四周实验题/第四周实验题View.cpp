
// ������ʵ����View.cpp : C������ʵ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ����.h"
#endif

#include "������ʵ����Doc.h"
#include "������ʵ����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ����View

IMPLEMENT_DYNCREATE(C������ʵ����View, CView)

BEGIN_MESSAGE_MAP(C������ʵ����View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C������ʵ����View ����/����

C������ʵ����View::C������ʵ����View()
{
	// TODO: �ڴ˴���ӹ������
	count = 0;

	up = 0; 
	down = 0;
	right = 0; 
	left=0;

}

C������ʵ����View::~C������ʵ����View()
{
}

BOOL C������ʵ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ����View ����

void C������ʵ����View::OnDraw(CDC*  pDC)
{
	C������ʵ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	//(2) �ڴ��ڿͻ����м����һ�����Σ��������ϵ��ĸ����������ʹ��������Ӧ�����ƶ���
	//��Home��ʹ���������ϽǷ������󣬰�End��ʱ���������½���С��������������ʱ�����λָ���ԭ����С��
	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(0, 0, 0));
	
	if (VK_UP) {
		up+=10;
		pDC->Rectangle(200, 200+up, 400, 400+up);
	}
		

}


// C������ʵ����View ��ӡ

BOOL C������ʵ����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʵ����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʵ����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʵ����View ���

#ifdef _DEBUG
void C������ʵ����View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ����Doc* C������ʵ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ����Doc)));
	return (C������ʵ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ����View ��Ϣ�������

//��������������
void C������ʵ����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	count =	0;
	x1 = point.x;

	CView::OnLButtonDown(nFlags, point);
}

///����ƶ�ͳ��
void C������ʵ����View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	count++;

	CView::OnMouseMove(nFlags, point);
}


//���̧��
void C������ʵ����View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	x2 = point.x;
	if(count!=0)
		s.Format(_T("MouseMove����:%d ��,ÿ�κ����ƶ���%d ���ص�"),count,(abs(x2-x1)/count));
	else
		s.Format(_T("MouseMove����:%d ��,ÿ�κ����ƶ���%d ���ص�"), count,0);
	dc.TextOutW(100, 100, s);

	CView::OnLButtonUp(nFlags, point);
}
