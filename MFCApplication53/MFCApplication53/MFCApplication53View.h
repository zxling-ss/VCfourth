
// MFCApplication53View.h: CMFCApplication53View 类的接口
//

#pragma once


class CMFCApplication53View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication53View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication53View)

// 特性
public:
	CMFCApplication53Doc* GetDocument() const;

// 操作
public:
	POINT p,p1, p2, p3;
	CRect cr1;
	CRect cr2;
	int a, b, c;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplication53View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
};

#ifndef _DEBUG  // MFCApplication53View.cpp 中的调试版本
inline CMFCApplication53Doc* CMFCApplication53View::GetDocument() const
   { return reinterpret_cast<CMFCApplication53Doc*>(m_pDocument); }
#endif

