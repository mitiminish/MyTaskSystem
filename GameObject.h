#pragma once
#include "DxLib.h"
#include "UpdateInterface.h"
#include "DrawInterface.h"
class CGameObject
	:virtual public CUpdateInterface,
	virtual public CDrawInterface
{

public:
	virtual void upDate(){};
	virtual void draw(){};
	virtual void init(){};
	CGameObject();
	virtual ~CGameObject();
};

