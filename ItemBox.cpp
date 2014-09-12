#include "ItemBox.h"

std::unordered_map<std::string, CGameTask*> CItemBox::itemBox;

CGameTask* CItemBox::findItem(std::string name){
	return itemBox[name];
}

void CItemBox::addItem(std::string name, CGameTask* obj){
	itemBox[name] = obj;
}

void CItemBox::clearItemBox(){
	itemBox.clear();
}
void CItemBox::eraseItem(std::string name){
	itemBox.erase(name);
}

CItemBox::CItemBox()
{
}


CItemBox::~CItemBox()
{
}
