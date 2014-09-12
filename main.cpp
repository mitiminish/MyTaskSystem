//*
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
//*/
/*
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define DEBUG_CLIENTBLOCK   new( _CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
*/

#include "DxLib.h"
#include "GameManager.h"
#include "KeyManager.h"
#include "MouseManager.h"


#include "KeyUI.h"

#include "MouseUI.h"
#include "EnumTest.h"
#include "FpsController.h"


int processLoop(){
	if (ProcessMessage() == -1)return -1;
	if (ClearDrawScreen() == -1)return -1;
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)return -1;
	if (clsDx() == -1)return -1;
	return 0;
}



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	CGameManager::addTask(CMouseManager::getInstance(), "mouseManager", -100, false);
	CGameManager::addTask(CKeyManager::getInstance(), "keyManager", -100, false);
	

	CGameManager::addTask(new CKeyUI(), "keyUI", -10);
	CGameManager::addTask(new CMouseUI(), "clickable_manager", -10);
	
	CGameManager::addTask(new CEnumTest(), "test", 10);

	CGameManager::addTask(new CFpsController(), "fps", INT_MAX);
	
	while (processLoop() == 0){
		CGameManager::playAllTask();
		ScreenFlip();
	}

	CGameManager::removeAllTask();
	InitFontToHandle();
	//?
	DxLib_End();				// ＤＸライブラリ使用の終了処理




	return 0;				// ソフトの終了 
}