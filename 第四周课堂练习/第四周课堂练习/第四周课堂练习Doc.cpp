
// �����ܿ�����ϰDoc.cpp : C�����ܿ�����ϰDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ܿ�����ϰ.h"
#endif

#include "�����ܿ�����ϰDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C�����ܿ�����ϰDoc

IMPLEMENT_DYNCREATE(C�����ܿ�����ϰDoc, CDocument)

BEGIN_MESSAGE_MAP(C�����ܿ�����ϰDoc, CDocument)
END_MESSAGE_MAP()


// C�����ܿ�����ϰDoc ����/����

C�����ܿ�����ϰDoc::C�����ܿ�����ϰDoc()
{
	// TODO: �ڴ����һ���Թ������

	//��ʼ����������
	m_tagRec.top = 0;
	m_tagRec.left = 0;
	m_tagRec.right = 0;
	m_tagRec.bottom = 0;

}

C�����ܿ�����ϰDoc::~C�����ܿ�����ϰDoc()
{
}

BOOL C�����ܿ�����ϰDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C�����ܿ�����ϰDoc ���л�

void C�����ܿ�����ϰDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C�����ܿ�����ϰDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void C�����ܿ�����ϰDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C�����ܿ�����ϰDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C�����ܿ�����ϰDoc ���

#ifdef _DEBUG
void C�����ܿ�����ϰDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C�����ܿ�����ϰDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C�����ܿ�����ϰDoc ����
