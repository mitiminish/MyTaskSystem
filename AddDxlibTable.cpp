#include "AddDxlibTable.h"
static const char* const STR_CIRCLE = "Circle";
static const char* const STR_TEXT = "Text";
void CAddDxlibTable::init(){
	CClickableTable::init();
}


void CAddDxlibTable::onClick(){

}





CAddDxlibTable::CAddDxlibTable()
{
	std::string strArray[] = {
		STR_CIRCLE,STR_TEXT
	};
	int colNum = _countof(strArray);
	int rowNum = 1;
	
	this->setStrArray(strArray,colNum,rowNum);
	this->setXY(5, 50);
	this->setXYMargin(20, 20);
	this->setTextBoxXYMargin(5, 5);

}


CAddDxlibTable::~CAddDxlibTable()
{
}
