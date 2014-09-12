#pragma once
#include "GameObject.h"
#include "UpdateInterface.h"
#include "PriorityDefine.h"
class CMouseUI :
	virtual public CUpdateInterface
{
public:
	void upDate();
	void init();
	CMouseUI();
	virtual ~CMouseUI();
};

