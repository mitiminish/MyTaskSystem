#pragma once
#include "MouseManager.h"
#include "TextTable.h"
class CClickableTable :
	public CTextTable
{
private:
	bool isEnable;
	int textXMargin;
	int textYMargin;
public:

	void setIsEnable(bool is){
		isEnable = is;
	};
	void init();
	void exec();
	//テキストの周りにある四角がテキストからどれくらい離れているか
	void setTextBoxXYMargin(int x, int y);
	std::string getClickState();
	CClickableTable();
	virtual ~CClickableTable();
};

