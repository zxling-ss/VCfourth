
// �����ܿ�����ϰ.h : �����ܿ�����ϰ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�����ܿ�����ϰApp:
// �йش����ʵ�֣������ �����ܿ�����ϰ.cpp
//

class C�����ܿ�����ϰApp : public CWinAppEx
{
public:
	C�����ܿ�����ϰApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�����ܿ�����ϰApp theApp;
