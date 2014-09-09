#include "ItemBox.h"

std::unordered_map<std::string, CGameObject*> CItemBox::itemBox;

CGameObject* CItemBox::findItem(std::string name){
	return itemBox[name];
}

void CItemBox::addItem(std::string name, CGameObject* obj){
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
