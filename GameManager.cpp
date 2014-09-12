#include "GameManager.h"
#include "DrawInterface.h"
#include "UpdateInterface.h"
#include "DxLib.h"
std::list<taskObject_t> CGameManager::objList;
std::list<taskObject_t>::iterator CGameManager::itTask;
bool CGameManager::isNowTaskRemove=false;

void CGameManager::playAllTask(){
	itTask = objList.begin();
	while (itTask != objList.end())
	{
		CGameTask* nowTask = itTask->obj;
		CUpdateInterface *task = dynamic_cast<CUpdateInterface*>(nowTask);
		if (task != NULL){
			task->upDate();
		}
		if (isNowTaskRemove){
			isNowTaskRemove = false;
		}
		else{
			itTask++;
		}
	}
	itTask = objList.begin();
	while (itTask != objList.end()){
		CDrawInterface* drawObj = dynamic_cast<CDrawInterface*>(itTask->obj);
		if (drawObj != NULL){
			drawObj->draw();
		}
		if (isNowTaskRemove){
			isNowTaskRemove = false;
		}
		else{
			itTask++;
		}
	}
}

void CGameManager::removeTask(CGameTask* target){
	std::list<taskObject_t>::iterator it = objList.begin();
	for (; it != objList.end(); it++){
		if (it->obj == target){
			if (itTask == it){
				isNowTaskRemove = true;
				itTask++;
			}
			if (it->autoDelete){
				delete it->obj;
				it->obj = NULL;
			}
			objList.erase(it);
			return;
		}
	}
}

void CGameManager::removeAllTask(){
	std::list<taskObject_t>::iterator it;
	for (it = objList.begin(); it != objList.end(); it++){
		if (it->autoDelete){
			delete it->obj;
		}
	}
	objList.clear();
}




void CGameManager::addTask(taskObject_t task){
	if (task.obj == NULL)return;
	task.obj->init();

	std::list<taskObject_t>::iterator it = objList.begin();
	for (; it != objList.end(); it++){
		if (it->priority > task.priority){
			objList.insert(it, task);
			return;
		}
	}
	objList.push_back(task);
}
void CGameManager::addTask(CGameTask* obj, std::string name, int priority, bool autoDelete){
	taskObject_t taskObj;
	taskObj.name = name;
	taskObj.obj = obj;
	taskObj.priority = priority;
	taskObj.autoDelete = autoDelete;
	CGameManager::addTask(taskObj);
}

void CGameManager::setIterator(CCreateEnum *en){
	en->ipos = objList.begin();
	en->iend = objList.end();
}


void CGameManager::setBackIterator(CCreateBackEnum *ben){
	ben->ipos = objList.rbegin();
	ben->irend = objList.rend();
}

void CGameManager::debug_showAllTask(){
	std::list<taskObject_t>::iterator it = objList.begin();
	for (; it != objList.end(); it++){
		int prior = it->priority;
		std::string name = it->name;
		CGameTask* obj = it->obj;
		printfDx("prior:%d,name:%s\n",prior,name.c_str());
	}
}



CGameManager::CGameManager()
{

}


CGameManager::~CGameManager()
{
}
