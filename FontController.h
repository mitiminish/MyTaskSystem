#pragma once
#include <string>
#include <list>
struct font_data_t
{
	void* pt;
	int size;
};
class CFontController
{
private:
	static std::list<font_data_t> pList;
public:
	static void addFont(const char* fileName);
	static void clearFont();
	CFontController();
	~CFontController();
};

