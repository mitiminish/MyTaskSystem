#pragma once
#include "MouseManager.h"
#include "ClickableInterface.h"
#include "UpdateInterface.h"
#include "TextTable.h"

class CClickableTable :
	virtual public CTextTable,
	virtual public CClickableInterface
{
private:
	
	int textXMargin;
	int textYMargin;
	col_row_t now_inside;
public:
	bool isInside(const pt_t &pt);
	virtual void onClick();
	
	virtual void init();
	virtual void draw();
	//テキストの周りにある四角がテキストからどれくらい離れているか
	void setTextBoxXYMargin(int x, int y);
	std::string getClickString();
	CClickableTable();
	virtual ~CClickableTable();
};

