#pragma once
#include "GameObject.h"
#include <string>
//�Ԃɂ��鏈�����ǂꂮ�炢���Ԃ�
//�������Ă��邩�𒲂ׂ܂�
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

