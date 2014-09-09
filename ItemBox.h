#pragma once
#include <string>
#include <unordered_map>
#include "GameObject.h"
class CItemBox

{

	static std::unordered_map<std::string, CGameObject*> itemBox;
public:
	static CGameObject* findItem(std::string name);
	static void addItem(std::string name, CGameObject* obj);
	static void clearItemBox();
	static void eraseItem(std::string name);
	CItemBox();
	~CItemBox();
};

