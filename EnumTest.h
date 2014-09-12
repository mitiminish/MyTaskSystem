#pragma once
#include "GameObject.h"
#include "DxLib.h"
class CEnumTest :
	public CGameObject
{
public:
	static void setEnumTest();
	virtual void init();
	virtual void upDate();
	virtual void draw();
	CEnumTest();
	virtual ~CEnumTest();
	class TestClass :virtual public CDrawInterface{
	private:
		int x, y;
		int color;
	public:
		void init(){
			x = GetRand(640 - 100) + 50;
			y = GetRand(480 - 100) + 50;
			color = GetColor(255, 255, 255);
		};
		void draw(){
			DrawPixel(x, y, color);
		};
		TestClass(){
		};
		virtual ~TestClass(){
		};
	};
};

