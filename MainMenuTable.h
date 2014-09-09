#pragma once
#include "ClickableTable.h"
static const char* STR_MAIN_TABLE = "mainTable";
class CMainMenuTable :
	public CClickableTable
{
private:

public:
	void exec();
	void init();
	CMainMenuTable();
	virtual ~CMainMenuTable();
};

