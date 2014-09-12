#include "GraphicObject.h"
#include "DxLib.h"
void CGraphicObject::init(){
	
	GetGraphSize(handle, &width, &height);
}



void CGraphicObject::draw(){
	const pt_t pt = this->getPt();
	DrawRotaGraph(pt.x, pt.y, exRate, angle, handle, isUseTrans);
}

CGraphicObject::CGraphicObject()
{
}

CGraphicObject::CGraphicObject(int handle){
	this->handle = handle;
}


CGraphicObject::~CGraphicObject()
{
}
