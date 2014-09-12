#include "MainMenuTable.h"
#include "GameManager.h"
#include "ItemBox.h"
#include "AddDxlibTable.h"
#include "PriorityDefine.h"
const char* str_toukasyoku = "���ߐF�ύX";
const char* str_dxlibObject = "dxlib�I�u�W�F�N�g�̑}��";
const char* str_modoru = "�߂�";


void CMainMenuTable::draw(){
	CClickableTable::draw();
		
	
}

void CMainMenuTable::onClick(){
	std::string click_str = getClickString();
	if (click_str == str_modoru){
		CGameManager::removeTask(this);
		CItemBox::eraseItem(STR_MAIN_TABLE);
	}
	else if (click_str == str_dxlibObject){
		CGameManager::addTask(new CAddDxlibTable(), "addDxlib",CLICKABLE_OBJ_PRIO);
		CGameManager::removeTask(this);
		//CItemBox::eraseItem(STR_MAIN_TABLE);
	}
}
void CMainMenuTable::init(){
	CClickableTable::init();
}

CMainMenuTable::CMainMenuTable()
{
	std::string strArray[] = {
		{ str_toukasyoku },
		{ str_dxlibObject },
		{ str_modoru }
	};
	int rowCount = 1;
	int colCount = _countof(strArray);

	this->setStrArray(strArray, colCount, rowCount);
	this->setXY(0, 100);
	this->setXYMargin(5, 50);
	this->setTextBoxXYMargin(5, 5);
}


CMainMenuTable::~CMainMenuTable()
{
}
