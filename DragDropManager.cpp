#include "DragDropManager.h"



void CDragDropManager::init(){

}
void CDragDropManager::exec(){

}




CDragDropManager* CDragDropManager::getInstance(){
	static CDragDropManager manager=CDragDropManager();
	return &manager;
}


CDragDropManager::CDragDropManager()
{
}


CDragDropManager::~CDragDropManager()
{
}
