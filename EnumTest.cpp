#include "EnumTest.h"
#include "GameManager.h"
#include "CreateEnum.h"
#include "CheckTime.h"

void CEnumTest::setEnumTest(){
	CCheckTime *tm = new CCheckTime("EnumTest");
	CGameManager::addTask(tm, tm->getName().c_str(), 0, false);
	CGameManager::addTask(new CEnumTest(), "enumTest", 0);
	CGameManager::addTask(tm, tm->getName().c_str(), 0);
}

void CEnumTest::init(){
	//*
	for (int i = 0; i < 1024; i++){
		CGameManager::addTask(new TestClass(), "mikata", 100);
	}
	//*/
	//CGameManager::addTask(new TestClass(), "teki", 110);
}

void CEnumTest::upDate(){
	CPrioBackEnum backEnum = CPrioBackEnum();
	backEnum.createEnumration(99, 101);
	CGameTask* task;
	int count = 0;
	task = backEnum.getBack();
	while (task!=NULL){
		TestClass* tClass = dynamic_cast<TestClass*>(task);
		if (tClass != NULL){
			count++;
		}
		task = backEnum.getBack();
	}
	printfDx("%d\n", count);
}

void CEnumTest::draw(){

}

CEnumTest::CEnumTest()
{
}


CEnumTest::~CEnumTest()
{
}
