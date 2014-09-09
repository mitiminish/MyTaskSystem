#pragma once
#include "DxLib.h"
class CGameObject
{
private:
	bool isForInit;
public:
	virtual void exec(){};
	virtual void init(){};
	bool getIsForInit();
	void setIsForInit();
	CGameObject();
	virtual ~CGameObject();
};

