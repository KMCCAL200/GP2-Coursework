#pragma once

#include "../GameApplication/GameApplication.h"
#include "../GameApplication/ObjectManager.h"

class MyGame:public CGameApplication
{
public:
	MyGame(){};
	~MyGame(){};

	bool initGame();
private:
	//void positionObject(GameObject *pObjIn);
//	ObjectManager objectManager;
};