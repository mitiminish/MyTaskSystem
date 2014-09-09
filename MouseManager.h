#pragma once
#include "GameObject.h"
#include "Struct.h"
class CMouseManager :
	public CGameObject
{
	pt_t pt;
	int left_btn_cnt;
	int right_btn_cnt;
	CMouseManager();
public:
	void init();
	void exec();
	pt_t getMousePoint();
	int getLeftButtonInput();
	int getRightButtonInput();
	void debug_showMouseData();
	static CMouseManager* getInstance();
	
	~CMouseManager();
};

