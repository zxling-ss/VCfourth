
// �����ܿ�����ϰView.cpp : C�����ܿ�����ϰView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ܿ�����ϰ.h"
#endif

#include "�����ܿ�����ϰDoc.h"
#include "�����ܿ�����ϰView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ܿ�����ϰView

IMPLEMENT_DYNCREATE(C�����ܿ�����ϰView, CView)

BEGIN_MESSAGE_MAP(C�����ܿ�����ϰView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C�����ܿ�����ϰView ����/����

C�����ܿ�����ϰView::C�����ܿ�����ϰView()
{
	// TODO: �ڴ˴���ӹ������

}

C�����ܿ�����ϰView::~C�����ܿ�����ϰView()
{
}

BOOL C�����ܿ�����ϰView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����ܿ�����ϰView ����

void C�����ܿ�����ϰView::OnDraw(CDC* pDC)
{
	C�����ܿ�����ϰDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_tagRec);

	
}


// C�����ܿ�����ϰView ��ӡ

BOOL C�����ܿ�����ϰView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�����ܿ�����ϰView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�����ܿ�����ϰView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�����ܿ�����ϰView ���

#ifdef _DEBUG
void C�����ܿ�����ϰView::AssertValid() const
{
	CView::AssertValid();
}

void C�����ܿ�����ϰView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ܿ�����ϰDoc* C�����ܿ�����ϰView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ܿ�����ϰDoc)));
	return (C�����ܿ�����ϰDoc*)m_pDocument;
}
#endif //_DEBUG


// C�����ܿ�����ϰView ��Ϣ�������

//��������ƶ��������ڿͻ�����ʾ����λ����Ϣ
void C�����ܿ�����ϰView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC clientDC(this);
	CString s;
	s.Format(_T("������꣺%d,%d"),point.x,point.y);
	clientDC.TextOutW(20, 20, s);



	CView::OnMouseMove(nFlags, point);
}

//�������������£��ƶ�ֱ��̧���������̣��ڰ���ʱ��¼�����λ��,
void C�����ܿ�����ϰView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	C�����ܿ�����ϰDoc* pDoc = GetDocument();
	pDoc->m_tagRec.right = point.x;
	pDoc->m_tagRec.top= point.y;


	CView::OnLButtonDown(nFlags, point);
}

// �������������£��ƶ�ֱ��̧���������̣��ڰ���ʱ��¼�����λ��,��̧�𻭳�һ�����Σ��԰��º�̧���λ����Ϊ���ε����Խǡ�

void C�����ܿ�����ϰView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C�����ܿ�����ϰDoc* pDoc = GetDocument();
	pDoc->m_tagRec.left = point.x;
	pDoc->m_tagRec.bottom = point.y;

	//ǿ���ػ�
	InvalidateRect(NULL, TRUE);

	CView::OnLButtonUp(nFlags, point);
}
