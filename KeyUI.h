#pragma once
#include "UpdateInterface.h"
class CKeyUI :
	public CUpdateInterface
{
	bool isEnable;
public:
	void setIsEnable(bool is);
	void upDate();
	void init();
	CKeyUI();
	~CKeyUI();
};

