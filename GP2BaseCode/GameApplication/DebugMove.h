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

class DebugMove{

public:
	DebugMove()
	{
		dir = 0.5;
		Player1 = new CXBOXController(1);
	};

	~DebugMove(){};

	CXBOXController* Player1;
	float dir;

	XMFLOAT3 cameraPos(XMFLOAT3 fps);
	XMFLOAT3 lookAt(XMFLOAT3 fpsv);
};