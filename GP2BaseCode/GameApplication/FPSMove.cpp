#include "FPSMove.h"

XMFLOAT3 FPSMove::cameraPos(XMFLOAT3 fps)
{	
	float x = fps.x;
	float y = fps.y;
	float z = fps.z;

	if(fps.x<147 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN || GetAsyncKeyState(VK_DOWN) || Player1->GetState().Gamepad.sThumbLY < -10000))
	{//move camera back
		fps.x=x+dir;
	}
	if(fps.x>-73 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP || GetAsyncKeyState(VK_UP) || Player1->GetState().Gamepad.sThumbLY > 10000))
	{//move the camera left
		fps.x=x-dir;
	}
	if(fps.y>-30 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT || GetAsyncKeyState(VK_RIGHT) || Player1->GetState().Gamepad.sThumbLX > 10000))
	{//move the camera forward
		fps.y=y-dir;
	}
	if(fps.y<71 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT || GetAsyncKeyState(VK_LEFT) || Player1->GetState().Gamepad.sThumbLX < -10000))
	{//move the camera back
		fps.y=y+dir;
	}

	return fps;
}

XMFLOAT3 FPSMove::lookAt(XMFLOAT3 fpsv,XMFLOAT3 fps)
{		
	float x = fpsv.x;
	float y = fpsv.y;
	float z = fpsv.z;
	//MOVEMENT***********************************
	if(fps.x>-73 & fps.x<147 & fps.y>-30 & fps.y<71){

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
	}}
	//LOOK******************************************
	if(Player1->GetState().Gamepad.sThumbRY < -10000)
	{	
		//move view point up
		fpsv.z=z+dir;
	}
	if(Player1->GetState().Gamepad.sThumbRY > 10000)
	{
		//move the view point down
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
	//////////////////

	if(GetAsyncKeyState(VK_CONTROL))
	{	
		//move view point forward
		//fpsv.x=x+dir;

		POINT ptCursorPos;
		GetCursorPos(&ptCursorPos);
		float px = ptCursorPos.x;
		float py = ptCursorPos.y;
		fpsv.y=px;
		fpsv.z=py;
	}

		return fpsv;
}