#pragma once
#include "ClickableTable.h"
class CAddDxlibTable :
	public CClickableTable
{
public:
	virtual void onClick();
	void init();
	CAddDxlibTable();
	~CAddDxlibTable();
};

