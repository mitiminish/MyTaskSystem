#include "MouseUI.h"
#include "CreateEnum.h"
#include "GameTask.h"
#include "ClickableInterface.h"
#include "MouseManager.h"
void CMouseUI::init(){

}

void CMouseUI::upDate(){
	CMouseManager *manager = CMouseManager::getInstance();
	pt_t mouse_pt = manager->getMousePoint();
	int isLeftClick = manager->getLeftButtonInput();
	CPrioBackEnum back = CPrioBackEnum();
	back.createEnumration(CLICKABLE_OBJ_PRIO, CLICKABLE_OBJ_PRIO);
	CGameTask* task =back.getBack();

	while (task!=NULL)
	{
		CClickableInterface *cObj = dynamic_cast<CClickableInterface*>(task);
		if (cObj != NULL){
			if (cObj->isInside(mouse_pt)){
				if (isLeftClick){
					cObj->onClick();
				}
				break;
			}
		}
		task = back.getBack();
	}
}


CMouseUI::CMouseUI()
{
}


CMouseUI::~CMouseUI()
{
}
