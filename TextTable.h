#pragma once
#include "GameObject.h"
#include "Struct.h"

#include <vector>
#include <string>
//typedef std::vector<std::vector<std::string>> str_table;
class CTextTable :
	public CDrawInterface
{
	int colNum, rowNum;
	int textWidth, textHeight;
	int table_x, table_y;
	int margin_x, margin_y;
	int color;
	int font;
	std::vector <std::vector<std::string >> strData;
	
	void calc_maxStrLength();
public:
	
	//CreateFontToHandle()ÇÇ¬Ç©Ç¡Çƒèâä˙âª
	void setFont(int font);
	void setColor(int color);
	void setXY(int x, int y);
	void setXYMargin(int x_m, int y_m);
	void setStrArray(std::vector<std::vector<std::string>> strArray);
	void setStrArray(std::string strArray[], int colNum, int rowNum);
	
	void drawBox_aroundText(int LRmargin, int UDmargin, int line_width=1);
	void drawBox_innerBox(const col_row_t &colRow, int LRmargin, int UDmargin, int color);

	void draw();
	void init();
	
	bool isOnTable(pt_t const &pt, col_row_t *col_row);
	pt_t getTextSize();
	rect_t getRect(col_row_t col_row);
	std::string getString(col_row_t col_row);
	CTextTable();
	virtual ~CTextTable();
};

