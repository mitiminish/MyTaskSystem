#pragma once
#include "DxlibObject.h"
class CGraphicObject
	:public CDxlibObject
{
private:
	int handle;
	double exRate, angle;
	bool isUseTrans;
	int width, height;
public:
	
	void init();
	void draw();

	CGraphicObject();
	CGraphicObject(int handle);
	~CGraphicObject();
};

