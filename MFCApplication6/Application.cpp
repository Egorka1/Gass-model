#include "stdafx.h"
#include "Application.h"
#include "DialogStrt.h"

Application::Application() {}

BOOL Application::InitInstance() {
	DialogStrt dlg;
	dlg.DoModal();
	return TRUE;
};

Application::~Application() {}