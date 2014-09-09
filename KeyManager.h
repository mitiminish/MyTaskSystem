#pragma once
#include "GameObject.h"
//#include "GameObject.h"
#include <vector>
class CKeyManager :
	public CGameObject
{
private:
	std::vector<int> key_input;
protected:
	CKeyManager();
public:
	virtual void exec();
	virtual void init();
	int getKey(int val);
	static CKeyManager* getInstance();
	virtual ~CKeyManager();
};

