#include "MainMenuTable.h"
#include "GameManager.h"
#include "ItemBox.h"
const char* str_toukasyoku = "���ߐF�ύX";
const char* str_dxlibObject = "dxlib�I�u�W�F�N�g�̑}��";
const char* str_modoru = "�߂�";


void CMainMenuTable::exec(){
	CClickableTable::exec();
		
	std::string click_str = getClickState();
	if (click_str == ""){
		return;
	}
	else if (click_str == str_modoru){
		CGameManager::removeTask(this);
		CItemBox::eraseItem(STR_MAIN_TABLE);
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
