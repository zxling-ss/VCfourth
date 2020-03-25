﻿
// MFCApplication52View.h: CMFCApplication52View 类的接口
//

#pragma once


class CMFCApplication52View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication52View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication52View)

// 特性
public:
	CMFCApplication52Doc* GetDocument() const;

// 操作
public:
	CBitmap m;
	int m_nwidth;
	int m_nhight;
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
	virtual ~CMFCApplication52View();
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
};

#ifndef _DEBUG  // MFCApplication52View.cpp 中的调试版本
inline CMFCApplication52Doc* CMFCApplication52View::GetDocument() const
   { return reinterpret_cast<CMFCApplication52Doc*>(m_pDocument); }
#endif

