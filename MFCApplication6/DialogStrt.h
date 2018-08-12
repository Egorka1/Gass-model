#pragma once
#include "afxwin.h"
#include "resource.h"

class DialogStrt : public CDialog {
public:
	DialogStrt(CWnd* pParent = NULL);
	void Run();
	~DialogStrt();
private:
	DECLARE_MESSAGE_MAP();
};