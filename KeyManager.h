#pragma once
#include "UpdateInterface.h"
#include <vector>
class CKeyManager :
	public CUpdateInterface
{
private:
	std::vector<int> key_input;
protected:
	CKeyManager();
public:
	virtual void upDate();
	virtual void init();
	int getKey(int val);
	static CKeyManager* getInstance();
	virtual ~CKeyManager();
};

