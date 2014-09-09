#include "PadManager.h"
const int PAD_INPUT_MAX = 16;
void CPadManager::init(){
	CKeyManager* key = CKeyManager::getInstance();
	key->init();
	pad_input.resize(PAD_INPUT_MAX);
	config_pad.down = 0;
	config_pad.left = 1;
	config_pad.right = 2;
	config_pad.up = 3;
	config_pad.dush = 4;
	config_pad.jump = 5;
	config_pad.start = 15;
}

void pad_or_key(int *pad, int key){
	*pad = (*pad > key) ? *pad : key;
}

void CPadManager::exec(){
	CKeyManager* key = CKeyManager::getInstance();
	key->exec();

	int PadInput = GetJoypadInputState(DX_INPUT_PAD1);
	
	int mul = 1;
	for (int i = 0; i < PAD_INPUT_MAX; i++){
		if (PadInput & mul){
			pad_input[i]++;
		}
		else{
			pad_input[i] = 0;
		}
		mul *= 2;
	}
	int pad_array[PAD_INPUT_MAX] = {
		config_pad.left,config_pad.up,
		config_pad.right,config_pad.down,
		config_pad.jump,config_pad.dush,
		config_pad.start
	};
	int key_array[PAD_INPUT_MAX] = {
		KEY_INPUT_LEFT, KEY_INPUT_UP,
		KEY_INPUT_RIGHT, KEY_INPUT_DOWN,
		KEY_INPUT_Z, KEY_INPUT_X,
		KEY_INPUT_SPACE
	};
	for (int i = 0; i < PAD_INPUT_MAX; i++){
		int key_val = key_array[i];
		int pad_val = pad_array[i];
		CKeyManager *keyM = CKeyManager::getInstance();
		pad_or_key(&pad_input[pad_val], keyM->getKey(key_val));
	}
}
int CPadManager::configEnum_to_num(CONFIG_PAD_E pad){
	switch (pad)
	{
	case CONFIG_PAD_UP:
		return config_pad.up;
		break;
	case CONFIG_PAD_DOWN:
		return config_pad.down;
		break;
	case CONFIG_PAD_LEFT:
		return config_pad.left;
		break;
	case CONFIG_PAD_RIGHT:
		return config_pad.right;
		break;
	case CONFIG_PAD_JUMP:
		return config_pad.jump;
		break;
	case CONFIG_PAD_DUSH:
		return config_pad.dush;
		break;
	case CONFIG_PAD_START:
		return config_pad.start;
		break;
	default:
		break;
	}
	return -1;
}

int CPadManager::getKey(CONFIG_PAD_E key){
	int num = configEnum_to_num(key);
	return pad_input[num];
}

CPadManager* CPadManager::getInstance(){
	static CPadManager manager;
	return &manager;
}


CPadManager::CPadManager()
{
}


CPadManager::~CPadManager()
{
}
