#pragma once
#include <string>
#include <unordered_map>
#include "GameTask.h"	
class CItemBox

{

	static std::unordered_map<std::string, CGameTask*> itemBox;
public:
	static CGameTask* findItem(std::string name);
	static void addItem(std::string name, CGameTask* obj);
	static void clearItemBox();
	static void eraseItem(std::string name);
	CItemBox();
	~CItemBox();
};

