#pragma once
#include "GameTask.h"
class CDrawInterface :
	virtual public CGameTask
{
private:

public:
	virtual void draw(){};
	CDrawInterface();
	virtual ~CDrawInterface();
};

