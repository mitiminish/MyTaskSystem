#include "KeyUI.h"
#include "KeyManager.h"
#include "GameManager.h"
#include "MainMenuTable.h"
#include "ItemBox.h"
#include "MouseUI.h"
void CKeyUI::upDate(){
	CKeyManager* key = CKeyManager::getInstance();
	
	if (key->getKey(KEY_INPUT_A)==1){
		std::string name = STR_MAIN_TABLE;
		CGameTask* buf_obj = CItemBox::findItem(name);
		if (buf_obj == NULL){
			CMainMenuTable* obj = new CMainMenuTable();
			CGameManager::addTask(obj,name, CLICKABLE_OBJ_PRIO);
			CItemBox::addItem(name, obj);
		}
		else{
			CGameManager::removeTask(buf_obj);
			CItemBox::eraseItem(name);
		}		
	}
}

void CKeyUI::init(){

}

void CKeyUI::setIsEnable(bool is){
	this->isEnable = is;
}



CKeyUI::CKeyUI()
{
}


CKeyUI::~CKeyUI()
{
}
