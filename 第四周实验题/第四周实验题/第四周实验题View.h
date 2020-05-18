
// 第四周实验题View.h : C第四周实验题View 类的接口
//

#pragma once


class C第四周实验题View : public CView
{
protected: // 仅从序列化创建
	C第四周实验题View();
	DECLARE_DYNCREATE(C第四周实验题View)

// 特性
public:
	C第四周实验题Doc* GetDocument() const;
	int count = 0;				//鼠标移动--MouseMove
	int x1, x2;				//x1鼠标按下时横坐标，x2鼠标抬起时横坐标

	int up, down, right, left;

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
	virtual ~C第四周实验题View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 第四周实验题View.cpp 中的调试版本
inline C第四周实验题Doc* C第四周实验题View::GetDocument() const
   { return reinterpret_cast<C第四周实验题Doc*>(m_pDocument); }
#endif

