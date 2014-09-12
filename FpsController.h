#pragma once
#include "GameObject.h"
class CFpsController :
	public CGameObject
{
private:
	int fps_count;
	int first_time;
	int sample_num;
	double now_fps;
public:
	virtual void init();
	virtual void upDate();
	virtual void draw();
	CFpsController();
	~CFpsController();
};

