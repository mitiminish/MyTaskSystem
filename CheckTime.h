#pragma once
#include "GameObject.h"
#include <string>
//ŠÔ‚É‚ ‚éˆ—‚ª‚Ç‚ê‚®‚ç‚¢ŠÔ‚ª
//‚©‚©‚Á‚Ä‚¢‚é‚©‚ğ’²‚×‚Ü‚·
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

