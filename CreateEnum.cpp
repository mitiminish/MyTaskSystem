#include "CreateEnum.h"
#include "GameManager.h"


void CPrioBackEnum::createEnumration(int first, int end){
	this->firstPrio = first;
	this->endPrio = end;
	CGameManager::setBackIterator(this);
}

CGameTask* CPrioBackEnum::getBack(){
	while (ipos != irend){

		if (ipos->priority < this->firstPrio){
			ipos = irend;
			return NULL;
		}
		else if (ipos->priority <= this->endPrio){
			CGameTask* task = ipos->obj;
			ipos++;
			return task;
		}
		ipos++;
	}

	return NULL;
}