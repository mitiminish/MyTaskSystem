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
	//�e�L�X�g�̎���ɂ���l�p���e�L�X�g����ǂꂭ�炢����Ă��邩
	void setTextBoxXYMargin(int x, int y);
	std::string getClickState();
	CClickableTable();
	virtual ~CClickableTable();
};

