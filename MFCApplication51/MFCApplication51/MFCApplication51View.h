﻿
// MFCApplication51View.h: CMFCApplication51View 类的接口
//

#pragma once


class CMFCApplication51View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication51View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication51View)

// 特性
public:
	CMFCApplication51Doc* GetDocument() const;

// 操作
public:

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
	virtual ~CMFCApplication51View();
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
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFCApplication51View.cpp 中的调试版本
inline CMFCApplication51Doc* CMFCApplication51View::GetDocument() const
   { return reinterpret_cast<CMFCApplication51Doc*>(m_pDocument); }
#endif

