#include "ClickableTable.h"
void CClickableTable::init(){
	CTextTable::init();
}

void CClickableTable::draw(){
	CTextTable::draw();
	drawBox_aroundText(textXMargin, textYMargin);

	
	if (now_inside!=COL_ROW_NOT_FOUND){
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,80);

		drawBox_innerBox(now_inside, textXMargin, textYMargin, GetColor(255, 255, 0));

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	}
}

//Ç‹Ç¢ÉãÅ[ÉvåƒÇŒÇÍÇÈÇ‡ÇÃÇ∆Ç∑ÇÈ
bool CClickableTable::isInside(const pt_t &pt){
	return isOnTable(pt,&now_inside);
}

void CClickableTable::onClick(){

}

std::string CClickableTable::getClickString(){
	return getString(now_inside);
	
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
