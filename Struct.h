#pragma once

struct pt_t
{
	int x, y;
	pt_t(){
		this->x = 0;
		this->y = 0;
	}
	pt_t(int x, int y){
		this->x = x;
		this->y = y;
	}
	pt_t operator +(pt_t pt){
		this->x += pt.x;
		this->y += pt.y;
		return *this;
	}
	pt_t operator -(pt_t pt){
		this->x -= pt.x;
		this->y -= pt.y;
		return *this;
	}
	void operator +=(pt_t pt){
		this->x += pt.x;
		this->y += pt.y;
	}
	void operator -=(pt_t pt){
		this->x -= pt.x;
		this->y -= pt.y;
	}
};

struct rect_t
{
	pt_t pt;
	pt_t size;
};

struct col_row_t
{
	int col, row;
	col_row_t(int col, int row){
		this->col = col;
		this->row = row;
	}
	col_row_t(){
		this->col = 0;
		this->row = 0;
	}
};
