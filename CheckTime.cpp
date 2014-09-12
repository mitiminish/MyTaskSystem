#include "CheckTime.h"
#include "DxLib.h"
int CCheckTime::checkTimeCount=0;
//“ñ‰ñ’Ê‚é
void CCheckTime::init(){
	if (name.empty()){
		name = "checkTime";
		char buf[256];
		sprintf_s(buf, "%s_%d", name.c_str(), checkTimeCount);
		name = buf;
	}
}

//1ƒ‹[ƒv‚É‚Â‚«2‰ñ’Ê‚è‚Ü‚·
void CCheckTime::upDate(){
	LONGLONG lvar = GetNowHiPerformanceCount();
	if (isFirst){
		isFirst = false;
		lateCount = lvar;
	}
	else{
		isFirst = true;
		LONGLONG pastBuf = lvar - lateCount;
		if (pastBuf< INT_MAX){
			pastCount = (int)pastBuf;
		}
		else{
			pastCount = -1;
		}
	}	
}

void CCheckTime::draw(){
	if (isFirst){
		DrawFormatString(x, y, GetColor(255, 255, 255), "[%s:%05.2f]", name.c_str(), pastCount / 1000.0);
	}
	else{
		isFirst = true;
	}
	
}
void CCheckTime::setName(std::string str){
	this->name = str;
}

std::string CCheckTime::getName(){
	return name;
}

CCheckTime::CCheckTime()
{
	selfNum = checkTimeCount;
	x = 640 - 200;
	y = 100 + 18 * selfNum;
	checkTimeCount++;
	isFirst = true;
}

CCheckTime::CCheckTime(std::string str){
	*this = CCheckTime();
	setName(str);
}

CCheckTime::~CCheckTime()
{
	checkTimeCount--;
}
