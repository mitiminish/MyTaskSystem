#include "ClickableTable.h"
void CClickableTable::init(){
	CTextTable::init();
}
void CClickableTable::exec(){
	CTextTable::exec();
	drawBox_aroundText(textXMargin, textYMargin);

	col_row_t col_row;
	CMouseManager* mouse = CMouseManager::getInstance();
	if (isOnTable(mouse->getMousePoint(), &col_row)){
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,80);

		drawBox_innerBox(col_row, textXMargin, textYMargin, GetColor(255, 255, 0));

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	}
	printfDx("%s\n", getClickState().c_str());
}

std::string CClickableTable::getClickState(){
	CMouseManager* mouse = CMouseManager::getInstance();
	col_row_t col_row;
	if (mouse->getLeftButtonInput() > 0){
		if (isOnTable(mouse->getMousePoint(), &col_row)){
			return getString(col_row);
		}
	}
	
	return "";
}

void CClickableTable::setTextBoxXYMargin(int x, int y){
	textXMargin = x;
	textYMargin = y;
}

CClickableTable::CClickableTable()
{
	textXMargin = 0;
	textYMargin = 0;
}


CClickableTable::~CClickableTable()
{
}
