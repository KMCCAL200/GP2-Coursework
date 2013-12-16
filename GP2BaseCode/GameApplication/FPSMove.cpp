#include "FPSMove.h"

XMFLOAT3 FPSMove::cameraPos(XMFLOAT3 fps)
{	
	float x = fps.x;
	float y = fps.y;
	float z = fps.z;

	if((Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) || GetAsyncKeyState(VK_DOWN) || Player1->GetState().Gamepad.sThumbLY < -10000)
	{//move camera right
		fps.x=x+dir;
	}
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP || GetAsyncKeyState(VK_UP) || Player1->GetState().Gamepad.sThumbLY > 10000)
	{//move the camera left
		fps.x=x-dir;
	}
	if((Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) || GetAsyncKeyState(VK_RIGHT) || Player1->GetState().Gamepad.sThumbLX > 10000)
	{//move the camera forward
		fps.y=y-dir;
	}
	if((Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) || GetAsyncKeyState(VK_LEFT) || Player1->GetState().Gamepad.sThumbLX < -10000)
	{//move the camera back
		fps.y=y+dir;
	}
	return fps;
}

XMFLOAT3 FPSMove::lookAt(XMFLOAT3 fpsv)
{		
	float x = fpsv.x;
	float y = fpsv.y;
	float z = fpsv.z;
	//MOVEMENT***********************************
	if((Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) || GetAsyncKeyState(VK_DOWN) || Player1->GetState().Gamepad.sThumbLY < -10000)
	{	
		//move view point forward
		fpsv.x=x+dir;
	}
	if((Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) || GetAsyncKeyState(VK_UP) || Player1->GetState().Gamepad.sThumbLY > 10000)
	{
		//move the view point back
		fpsv.x=x-dir;
	}
	if((Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) || GetAsyncKeyState(VK_RIGHT) || Player1->GetState().Gamepad.sThumbLX > 10000)
	{
		//move the view point left
		fpsv.y=y-dir;
	}
	if((Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) || GetAsyncKeyState(VK_LEFT) || Player1->GetState().Gamepad.sThumbLX < -10000)
	{
		//move the view point right
		fpsv.y=y+dir;
	}
	//LOOK******************************************
	if(Player1->GetState().Gamepad.sThumbRY < -10000)
	{	
		//move view point forward
		fpsv.z=z+dir;
	}
	if(Player1->GetState().Gamepad.sThumbRY > 10000)
	{
		//move the view point back
		fpsv.z=z-dir;
	}
	if(Player1->GetState().Gamepad.sThumbRX > 10000)
	{
		//move the view point left
		fpsv.y=y-dir;
	}
	if(Player1->GetState().Gamepad.sThumbRX < -10000)
	{
		//move the view point right
		fpsv.y=y+dir;
	}


	return fpsv;
}