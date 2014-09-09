#include "DxLib.h"
#include "FontController.h"

std::list<font_data_t> CFontController::pList;

void CFontController::addFont(const char* fontName){
	int fontFileSize = FileRead_size(fontName);
	int handle = FileRead_open(fontName);
	void *buffer = malloc(fontFileSize);

	FileRead_read(buffer, fontFileSize, handle);
	FileRead_close(handle);

	DWORD font_num = 0;
	AddFontMemResourceEx(buffer, fontFileSize, NULL, &font_num);
	
	//è¡ãéÇ∑ÇÈÉäÉXÉgÇ…í«â¡
	font_data_t data;
	data.pt = buffer;
	data.size = fontFileSize;
	pList.push_back(data);
}

void CFontController::clearFont(){
	std::list<font_data_t>::iterator it;
	for (it = pList.begin(); it != pList.end(); it++){
		free(it->pt);
	}
	pList.clear();
}


CFontController::CFontController()
{
}


CFontController::~CFontController()
{
	CFontController::clearFont();
}
