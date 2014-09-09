#pragma once
#include "GameObject.h"
#include <string>
#include <list>
#include <unordered_map>
struct taskObject_t{
	int priority;
	std::string name;
	CGameObject *obj;
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
	static void addTask(CGameObject* obj, std::string name, int priority, bool autoDelete=true);
	static void removeTask(CGameObject* obj);
	static void removeAllTask();
	static void debug_showAllTask();
	CGameManager();
	~CGameManager();
};

