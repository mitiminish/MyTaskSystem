#include "TextTable.h"




void CTextTable::init(){
	if (font == -1){
		setFont(CreateFontToHandle(NULL, 20, 9));
	}
	if (color == -1){
		color = GetColor(255, 255, 255);
	}
}

void CTextTable::exec(){
	if (color == -1){
		color = 0xffffff;
		
	}
	if (font == -1){
		printfDx("font:-1\n");
		return;
	}
	else{

		int pos_x = table_x+margin_x;
		int pos_y = table_y+margin_y;
		DrawCircle(table_x, table_y, 8, GetColor(255, 0, 0));
		int box_width = textWidth + margin_x;
		int box_height = textHeight + margin_y;
		for (int i = 0; i < colNum; i++){
			for (int j = 0; j < rowNum; j++){
				std::string dat = strData[i][j];
				DrawStringToHandle(pos_x + box_width*j, pos_y + box_height*i,
					dat.c_str(), GetColor(255, 255, 255), font);
			}
		}
		/*
		DrawBox(table_x, table_y, pos_x + rowNum*box_width, pos_y + colNum*box_height, color, false);
		for (int i = 1; i <= colNum; i++){
			int now_height = table_y + box_height*i;
			DrawLine(table_x, now_height,
				table_x + margin_x + rowNum*box_width - 1, now_height, color);
			now_height -= textHeight;
			DrawLine(table_x, now_height,
				table_x + margin_x + rowNum*box_width - 1, now_height, color);
		}
		for (int i = 1; i <= rowNum; i++){
			int now_x = table_x + box_width*i;
			DrawLine(now_x, table_y, now_x, table_y + margin_y + colNum*box_height - 1, color);
			now_x -= textWidth;
			DrawLine(now_x, table_y, now_x, table_y + margin_y + colNum*box_height - 1, color);
		}
		//*/
	}
}

void CTextTable::drawBox_aroundText(int LRmargin, int UDmargin, int line_width){
	
	int width = textWidth+LRmargin*2;
	int height = textHeight+UDmargin*2;
	for (int i = 0; i < colNum; i++){
		for (int j = 0; j < rowNum; j++){
			int pos_x = table_x + margin_x+(textWidth+margin_x)*j;
			int pos_y = table_y + margin_y+(textHeight+margin_y)*i;
			int draw_x = pos_x - LRmargin;
			int draw_y = pos_y - UDmargin;
			for (int k = 0; k < line_width; k++){
				DrawBox(draw_x-k, draw_y-k,draw_x+width+k,draw_y+height+k, color, FALSE);
			}
		}
	}
}

void CTextTable::drawBox_innerBox(col_row_t col_row, int LRmargin, int UDmargin, int boxColor){
	//テキストの原点
	int pos_x = table_x + margin_x + (textWidth + margin_x)*col_row.row;
	int pos_y = table_y + margin_y + (textHeight + margin_y)*col_row.col;
	//描画する場所
	int draw_x = pos_x - LRmargin;
	int draw_y = pos_y - UDmargin;
	//箱の大きさ
	int width = textWidth + LRmargin * 2;
	int height = textHeight + UDmargin * 2;
	DrawBox(draw_x, draw_y, draw_x + width, draw_y + height, boxColor, TRUE);
	
}


void CTextTable::setFont(int font){
	this->font = font;
	calc_maxStrLength();
}

void CTextTable::calc_maxStrLength(){
	if (font == -1 || strData.size() == 0){
		return;
	}
	int index_i = 0, index_j = 0;
	int size_buf = 0;
	for (int i = 0; i < colNum; i++){
		for (int j = 0; j < rowNum; j++){
			int str_size = strData[i][j].size();
			if (size_buf < str_size){
				size_buf = str_size;
				index_i = i;
				index_j = j;
			}
		}
	}
	std::string dat = strData[index_i][index_j];
	textWidth = GetDrawStringWidthToHandle(dat.c_str(), dat.size(), font);
	int size = -1;
	GetFontStateToHandle(NULL, &size, NULL, font);
	textHeight = size;
}


void CTextTable::setColor(int color){
	this->color = color;
}

void CTextTable::setStrArray(std::vector<std::vector<std::string>> strArray){
	colNum = strArray.size();
	rowNum = strArray[0].size();
	strData.resize(colNum);
	for (int i = 0; i < colNum; i++){
		std::copy(strArray[i].begin(), strArray[i].end(), std::back_inserter(strData[i]));
	}
	calc_maxStrLength();
}

void CTextTable::setStrArray(std::string strArray[], int colNum, int rowNum){
	this->colNum = colNum;
	this->rowNum = rowNum;
	strData.resize(colNum);
	for (int i = 0; i < colNum; i++){
		for (int j = 0; j < rowNum; j++){
			strData[i].push_back(strArray[i*rowNum + j]);
		}
	}
}

void CTextTable::setXY(int x, int y){
	this->table_x = x;
	this->table_y = y;
}

void CTextTable::setXYMargin(int x_m, int y_m){
	this->margin_x = x_m;
	margin_y = y_m;
}

bool CTextTable::isOnTable(pt_t pt, col_row_t *col_row){
	pt_t table_pt = pt_t(this->table_x+margin_x, this->table_y+margin_y);
	pt_t rel_pt = pt-table_pt;
	for (int i = 0; i < colNum; i++){
		for (int j = 0; j < rowNum; j++){
			int box_width = textWidth ;
			int box_height = textHeight;
			int now_x = (textWidth + margin_x)*j;
			int now_y = (textHeight + margin_y)*i;
			
			if (now_x <= rel_pt.x && rel_pt.x <= box_width + now_x
				&& now_y <= rel_pt.y && rel_pt.y <= box_height + now_y){
				*col_row = col_row_t(i, j);
				return true;
			}
		}
	}
	return false;
}

pt_t CTextTable::getTextSize(){
	return pt_t(this->textWidth, this->textHeight);
}

rect_t CTextTable::getRect(col_row_t col_row){
	rect_t rect;
	rect.pt.x = table_x+margin_x+ (textWidth + margin_x)*col_row.row;
	rect.pt.y = table_y+margin_y+ (textHeight + margin_y)*col_row.col;
	rect.size.x = textWidth;
	rect.size.y = textHeight;
	return rect;
}

std::string CTextTable::getString(col_row_t col_row){
	return this->strData[col_row.col][col_row.row];
}

CTextTable::CTextTable()
{
	font = -1;
	color = -1;
	table_x = table_y = 0;
	margin_x = margin_y = 0;
}


CTextTable::~CTextTable()
{
}
