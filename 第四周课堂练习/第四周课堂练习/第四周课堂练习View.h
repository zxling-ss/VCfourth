
// �����ܿ�����ϰView.h : C�����ܿ�����ϰView ��Ľӿ�
//

#pragma once


class C�����ܿ�����ϰView : public CView
{
protected: // �������л�����
	C�����ܿ�����ϰView();
	DECLARE_DYNCREATE(C�����ܿ�����ϰView)

// ����
public:
	C�����ܿ�����ϰDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C�����ܿ�����ϰView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // �����ܿ�����ϰView.cpp �еĵ��԰汾
inline C�����ܿ�����ϰDoc* C�����ܿ�����ϰView::GetDocument() const
   { return reinterpret_cast<C�����ܿ�����ϰDoc*>(m_pDocument); }
#endif

