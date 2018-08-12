#pragma once
#include "afxwin.h"

class Application : public CWinApp {
public:
	Application();
	virtual BOOL InitInstance();
	~Application();
};