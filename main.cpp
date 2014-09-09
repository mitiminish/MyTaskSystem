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
#include "PadManager.h"
#include "MouseManager.h"


#include "FontController.h"
#include "KeyUI.h"

#include "MainMenuTable.h"


int processLoop(){
	if (ProcessMessage() == -1)return -1;
	if (ClearDrawScreen() == -1)return -1;
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)return -1;
	if (clsDx() == -1)return -1;
	return 0;
}



// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(98);

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);
	CFontController::addFont("azuki.ttf");

	int cnt = 0;
	CGameManager::addTask(CPadManager::getInstance(), "keyManager", -1, false);
	CGameManager::addTask(CMouseManager::getInstance(), "mouseManager", -2, false);
	CGameManager::addTask(new CKeyUI(), "keyUI", 0);
	
	
	while (processLoop() == 0){
		CGameManager::playAllTask();
		CGameManager::debug_showAllTask();
		ScreenFlip();
	}

	CGameManager::removeAllTask();
	CFontController::clearFont();
	InitFontToHandle();
	//?
	DxLib_End();				// �c�w���C�u�����g�p�̏I������




	return 0;				// �\�t�g�̏I�� 
}