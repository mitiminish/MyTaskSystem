#pragma once
#include "GameObject.h"
class CKeyUI :
	public CGameObject
{
	bool isEnable;
public:
	void setIsEnable(bool is);
	void exec();
	void init();
	CKeyUI();
	~CKeyUI();
};

