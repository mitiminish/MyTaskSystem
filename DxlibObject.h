#pragma once
#include "Struct.h"
#include "DrawInterface.h"

class CDxlibObject :
	public CDrawInterface
{
private:
	pt_t pt;
public:
	void setPt(const pt_t& pt){
		this->pt = pt;
	};
	const pt_t& getPt(){
		return pt;
	};
	virtual void draw()=0;
	virtual void init()=0;
	CDxlibObject();
	~CDxlibObject();
};

