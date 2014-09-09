#include "GameObject.h"

bool CGameObject::getIsForInit(){
	return this->isForInit;
}
void CGameObject::setIsForInit(){
	this->isForInit = true;
}

CGameObject::CGameObject()
{
	this->isForInit = false;
}


CGameObject::~CGameObject()
{
}
