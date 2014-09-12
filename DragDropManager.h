#pragma once

#include "UpdateInterface.h"
class CDragDropManager :
	public CUpdateInterface
{
	CDragDropManager();
public:
	void init();
	void upDate();
	static CDragDropManager* getInstance();
	~CDragDropManager();
};

