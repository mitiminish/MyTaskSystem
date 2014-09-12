#pragma once
#include "UpdateInterface.h"
#include "Struct.h"
class CMouseManager :
	public CUpdateInterface
{
	pt_t pt;
	int left_btn_cnt;
	int right_btn_cnt;
	CMouseManager();
public:
	void init();
	void upDate();
	pt_t getMousePoint();
	int getLeftButtonInput();
	int getRightButtonInput();
	void debug_showMouseData();
	static CMouseManager* getInstance();
	
	~CMouseManager();
};

