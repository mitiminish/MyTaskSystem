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
	pt_t(const pt_t &pt){
		this->x = pt.x;
		this->y = pt.y;
	}
	//*
	pt_t operator +(const pt_t& pt)const{
		pt_t resPt = pt_t(*this);
		resPt.x += pt.x;
		resPt.y += pt.y;
		return resPt;
	}
	pt_t operator -(const pt_t &pt)const{
		pt_t resPt = pt_t(*this);
		resPt.x -= pt.x;
		resPt.y -= pt.y;
		return resPt;
	}
	void operator +=(const pt_t &pt){
		this->x += pt.x;
		this->y += pt.y;
	}
	void operator -=(const pt_t &pt){
		this->x -= pt.x;
		this->y -= pt.y;
	}
	//*/
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
	bool operator ==(const col_row_t &cl)const{
		return (this->col == cl.col && this->row == cl.row);
	}
	bool operator !=(const col_row_t &cl){
		return !(*this == cl);
	}

};
static const col_row_t COL_ROW_NOT_FOUND = col_row_t(-1, -1);