#include "KeyManager.h"
const int KEY_INPUT_MAX = 256;
void CKeyManager::init(){
	key_input.resize(KEY_INPUT_MAX);
}
void CKeyManager::exec(){
	char array[KEY_INPUT_MAX];
	GetHitKeyStateAll(array);
	for (int i = 0; i < _countof(array); i++){
		if (array[i] != 0){
			key_input[i]++;
		}
		else{
			key_input[i] = 0;
		}
	}
}
CKeyManager* CKeyManager::getInstance(){
	static CKeyManager manager;
	return &manager;
}

int CKeyManager::getKey(int val){
	return key_input[val];
}

CKeyManager::CKeyManager()
{
}


CKeyManager::~CKeyManager()
{
}
