#pragma once
#include <list>
#include <string>
struct taskObject_t;
class CGameManager;
class CGameTask;
class CCreateEnum
{
	
protected:
	std::list<taskObject_t>::iterator ipos, iend;
public:
	friend CGameManager;
	virtual CGameTask* getNext()=0;
	CCreateEnum(){};
	virtual ~CCreateEnum(){};
};

//‚±‚±‚©‚ç‹tŒü‚«‚Éenum‚·‚é‚â‚Â
class CCreateBackEnum
{
protected:
	std::list<taskObject_t>::reverse_iterator ipos, irend;
	
public:
	friend CGameManager;
	virtual CGameTask* getBack()=0;
	CCreateBackEnum(){};
	virtual ~CCreateBackEnum(){};
};

class CPrioBackEnum :public CCreateBackEnum{
private:
	int firstPrio, endPrio;
public:
	void createEnumration(int firstPrio, int endPrio);
	CGameTask* getBack();
	CPrioBackEnum(){};
	virtual ~CPrioBackEnum(){};
};