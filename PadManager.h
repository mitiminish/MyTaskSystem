#pragma once
#include "KeyManager.h"
enum CONFIG_PAD_E{
	CONFIG_PAD_UP,CONFIG_PAD_DOWN,CONFIG_PAD_LEFT,CONFIG_PAD_RIGHT,
	CONFIG_PAD_JUMP,CONFIG_PAD_DUSH,CONFIG_PAD_START
};
struct pad_key_t{
	int up, down, left, right;
	int jump, dush, start;
};
class CPadManager :
	public CKeyManager
{
private:
	int configEnum_to_num(CONFIG_PAD_E pad);
	pad_key_t config_pad;
	std::vector<int> pad_input;
	CPadManager();
public:
	void exec();
	void init();
	int getKey(CONFIG_PAD_E key);
	static CPadManager* getInstance();
	~CPadManager();
};

