
// �����ܿ�����ϰDoc.h : C�����ܿ�����ϰDoc ��Ľӿ�
//


#pragma once


class C�����ܿ�����ϰDoc : public CDocument
{
protected: // �������л�����
	C�����ܿ�����ϰDoc();
	DECLARE_DYNCREATE(C�����ܿ�����ϰDoc)

// ����
public:
	CRect m_tagRec;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C�����ܿ�����ϰDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
