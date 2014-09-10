#pragma once
#include "UpdateInterface.h"
class CCheckMouse :
	virtual public CUpdateInterface
{
public:
	virtual void upDate();
	CCheckMouse();
	~CCheckMouse();
};

