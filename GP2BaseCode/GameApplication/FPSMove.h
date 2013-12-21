//This file is Kerri McCallum's work
#pragma once
#include "CameraComponent.h"
#include "Transform.h"
#include "GameComponent.h"
#include "GameObject.h"
#include <windows.h>
#define _XM_NO_INTRINSICS_
#include <xnamath.h>
#include "CXBOXController.h"

using namespace std;

class FPSMove{

public:
	FPSMove()
	{
		dir = 0.1;
		Player1 = new CXBOXController(1);
	};
	~FPSMove(){};

	CXBOXController* Player1;
	float dir;
	//Function for setting camera postion
	XMFLOAT3 cameraPos(XMFLOAT3 fps);
	//Function for setting look at postion
	XMFLOAT3 lookAt(XMFLOAT3 fpsv,XMFLOAT3 fps);
};