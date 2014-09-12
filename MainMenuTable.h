#pragma once
#include "ClickableTable.h"

static const char* STR_MAIN_TABLE = "mainTable";
class CMainMenuTable :
	public CClickableTable
{
private:

public:
	virtual void onClick();
	virtual void draw();
	virtual void init();
	CMainMenuTable();
	virtual ~CMainMenuTable();
};

