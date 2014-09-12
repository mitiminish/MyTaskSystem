#pragma once
#include "GameTask.h"
#include <string>
#include <list>
#include <unordered_map>
#include "CreateEnum.h"
struct taskObject_t{
	int priority;
	std::string name;
	CGameTask *obj;
	bool autoDelete;
};


class CGameManager
{
private:
	static std::list<taskObject_t> objList;
	static std::list<taskObject_t>::iterator itTask;
	static bool isNowTaskRemove;
public:
	static void playAllTask();
	static void addTask(taskObject_t task);
	static void addTask(CGameTask* obj, std::string name, int priority, bool autoDelete = true);
	static void removeTask(CGameTask* obj);
	static void removeAllTask();
	
	//これを呼び出すことで重くなる可能性も考慮せよ
	static void debug_showAllTask();
	static void setIterator(CCreateEnum *en);
	static void setBackIterator(CCreateBackEnum *en);
	CGameManager();
	~CGameManager();
};

