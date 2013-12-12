#pragma once
#include "CameraComponent.h"
#include "Transform.h"
#include "GameComponent.h"
#include "GameObject.h"
#include <windows.h>
#define _XM_NO_INTRINSICS_
#include <xnamath.h>
using namespace std;
class FPSMove{
public:
	FPSMove(){};
	~FPSMove(){};

	XMFLOAT3 movement(XMFLOAT3 fps)
	{		
		float x = fps.x;
		float y = fps.y;
		float dir = 1;

		if(GetAsyncKeyState(VK_UP))
		{	
			//move camera forwars
			fps.x=x+dir;
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			//move the camera back
			fps.x=x-dir;
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			//move the camera left
			fps.y=y-dir;
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			//move the camera right
			fps.y=y+dir;
		}
		return fps;
	};
};