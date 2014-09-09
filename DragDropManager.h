#pragma once
#include "GameObject.h"
class CDragDropManager :
	public CGameObject
{
	CDragDropManager();
public:
	void init();
	void exec();
	static CDragDropManager* getInstance();
	~CDragDropManager();
};

