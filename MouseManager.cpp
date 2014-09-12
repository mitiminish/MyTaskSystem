#include "DxLib.h"
#include "MouseManager.h"

void CMouseManager::upDate(){
	int x, y;
	GetMousePoint(&x, &y);
	pt.x = x;
	pt.y = y;

	int mouseInput = GetMouseInput();
	if (mouseInput & MOUSE_INPUT_LEFT){
		left_btn_cnt++;
	}
	else{
		left_btn_cnt = 0;
	}

	if (mouseInput & MOUSE_INPUT_RIGHT){
		right_btn_cnt++;
	}
	else{
		right_btn_cnt = 0;
	}
}

pt_t CMouseManager::getMousePoint(){
	return this->pt;
}



void CMouseManager::init(){
	left_btn_cnt = 0;
	right_btn_cnt = 0;
}

int CMouseManager::getLeftButtonInput(){
	return left_btn_cnt;
}
int CMouseManager::getRightButtonInput(){
	return right_btn_cnt;
}

CMouseManager* CMouseManager::getInstance(){
	static CMouseManager manager;
	return &manager;
}

void CMouseManager::debug_showMouseData(){
	printfDx("mouse_btn:%d,%d\n", pt.x, pt.y);
	printfDx("left_btn:%d\n", left_btn_cnt);
	printfDx("right_btn:%d\n", right_btn_cnt);
}

CMouseManager::CMouseManager()
{
}


CMouseManager::~CMouseManager()
{
}
