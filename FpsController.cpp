#include "FpsController.h"
#include "DxLib.h"
void CFpsController::init(){
	first_time = GetNowCount();
	fps_count = 1;
	sample_num = 60;
	now_fps = 0;
}

void CFpsController::upDate(){
	if (fps_count == sample_num){
		int now_count = GetNowCount();
		//àÍâÒÇÃÉãÅ[ÉvÇ…âΩïbÇ©Ç©Ç¡ÇƒÇ¢ÇÈÇ©ÇÃãtêî
		now_fps = sample_num / (double)(now_count - first_time)*1000.0;

		first_time = now_count;
		fps_count = 0;
	}
	fps_count++;
}

void CFpsController::draw(){
	DrawFormatString(640 - 60, 480 - 20, GetColor(255, 255, 255), "[%.1f]", now_fps);
}

CFpsController::CFpsController()
{
}


CFpsController::~CFpsController()
{
}
