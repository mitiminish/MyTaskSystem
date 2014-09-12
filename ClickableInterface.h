#pragma once
#include "Struct.h"
class CClickableInterface
{
public:
	virtual void onClick() = 0;
	virtual bool isInside(const pt_t &pt) = 0;
	CClickableInterface();
	~CClickableInterface();
};

