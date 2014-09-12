#pragma once
#include "GameTask.h"
class CUpdateInterface :
	virtual public CGameTask
{
public:
	virtual void upDate();
	CUpdateInterface();
	virtual ~CUpdateInterface();
};

