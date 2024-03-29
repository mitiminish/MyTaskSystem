#pragma once
#include "GameObject.h"
#include <string>
//間にある処理がどれぐらい時間が
//かかっているかを調べます
//
class CCheckTime :
	public CGameObject
{
	static int checkTimeCount;
	int selfNum;
	LONGLONG lateCount;
	int pastCount;
	int x, y;
	std::string name;
	bool isFirst;
public:
	void setName(std::string str);
	std::string getName();
	void init();
	void upDate();
	void draw();
	CCheckTime();
	CCheckTime(std::string str);
	virtual ~CCheckTime();
};

