//This file is Kerri McCallum's work
#include "DebugMove.h"
//Moves the camera without the constraints of the world
//Holds old mouse position
float oldx=-100;
float oldy=-100;

XMFLOAT3 DebugMove::cameraPos(XMFLOAT3 fps)
{	
	//***************MOVEMENT USING LEFT ANALOG STICK or D-PAD or KEYBOARD********************

	//Move stick up or press up arrow on keyboard or d-pad
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP || GetAsyncKeyState(VK_UP) || Player1->GetState().Gamepad.sThumbLY > 10000)
	{
		//move the camera forward
		fps.x=fps.x-dir;
	}
	//Move stick down or press down arrow on keyboard or d-pad
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN || GetAsyncKeyState(VK_DOWN) || Player1->GetState().Gamepad.sThumbLY < -10000)
	{
		//move camera back
		fps.x=fps.x+dir;
	}  	
	//Move stick right or press right arrow on keyboard or d-pad
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT || GetAsyncKeyState(VK_RIGHT) || Player1->GetState().Gamepad.sThumbLX > 10000)
	{
		//move the camera right
		fps.y=fps.y-dir;
	}
	//Move stick left or press left arrow on keyboard or d-pad
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT || GetAsyncKeyState(VK_LEFT) || Player1->GetState().Gamepad.sThumbLX < -10000)
	{
		//move the camera left
		fps.y=fps.y+dir;
	}
	//press W on keyboard or right trigger
	if(Player1->GetState().Gamepad.bRightTrigger || GetAsyncKeyState(0x57))
	{
		//move the camera up
		fps.z=fps.z+dir;
	}
	//press S on keyboard or left trigger
	if(Player1->GetState().Gamepad.bLeftTrigger || GetAsyncKeyState(0x53))
	{
		//move the camera down
		fps.z=fps.z-dir;
	}
	//Press X on keyboard or Back on XBOX controller
	if(GetAsyncKeyState(0x58) || Player1->GetState().Gamepad.wButtons &  XINPUT_GAMEPAD_BACK)
	{
		//Resets the position if you get lost
		fps.x=140;
		fps.z=10;
		fps.y=0;
	}
	//return updated position
	return fps;
}

XMFLOAT3 DebugMove::lookAt(XMFLOAT3 fpsv)
{		
	//***************MOVEMENT USING LEFT ANALOG STICK or D-PAD or KEYBOARD********************

	//Move stick up or press up arrow on keyboard or d-pad
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP || GetAsyncKeyState(VK_UP) || Player1->GetState().Gamepad.sThumbLY > 10000)
	{
		//move the view point forward
		fpsv.x=fpsv.x-dir;
	}
	//Move stick down or press down arrow on keyboard or d-pad
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN || GetAsyncKeyState(VK_DOWN) || Player1->GetState().Gamepad.sThumbLY < -10000)
	{	
		//move view point back
		fpsv.x=fpsv.x+dir;
	}
	//Move stick right or press right arrow on keyboard or d-pad
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT || GetAsyncKeyState(VK_RIGHT) || Player1->GetState().Gamepad.sThumbLX > 10000)
	{
		//move the view point right
		fpsv.y=fpsv.y-dir;
	}
	//Move stick left or press left arrow on keyboard or d-pad
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT || GetAsyncKeyState(VK_LEFT) || Player1->GetState().Gamepad.sThumbLX < -10000)
	{
		//move the view point left
		fpsv.y=fpsv.y+dir;
	}
	//press W on keyboard or right trigger
	if(Player1->GetState().Gamepad.bRightTrigger || GetAsyncKeyState(0x57))
	{
		//move view point up
		fpsv.z=fpsv.z+dir;
	}
	//press S on keyboard or left trigger
	if(Player1->GetState().Gamepad.bLeftTrigger || GetAsyncKeyState(0x53))
	{
		//move view point down
		fpsv.z=fpsv.z-dir;
	}
	//******************LOOK USING RIGHT ANALOG STICK************************

	//Move stick down
	if(Player1->GetState().Gamepad.sThumbRY < -10000)
	{	
		//move view point up
		fpsv.z=fpsv.z+dir;
	}
	//Move stick up
	if(Player1->GetState().Gamepad.sThumbRY > 10000)
	{
		//move view point down
		fpsv.z=fpsv.z-dir;
	}
	//Move stick left
	if(Player1->GetState().Gamepad.sThumbRX < -10000)
	{
		//move view point left
		fpsv.y=fpsv.y+dir;
	}
	//Move stick right
	if(Player1->GetState().Gamepad.sThumbRX > 10000)
	{
		//move view point right
		fpsv.y=fpsv.y-dir;
	}
		//Hold down left mouse button and move mouse
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		//Finds where the pointer is on the screen
		POINT ptCursorPos;
		GetCursorPos(&ptCursorPos);
		//Sets the pointer position to look at position
		float px = ptCursorPos.x;
		float py = ptCursorPos.y;
		//move mouse up
		if(py<oldy)
		{	
			//move look position up
			fpsv.z=fpsv.z+dir;
		}
		//move mouse down
		if(py>oldy)
		{
			//move look position down
			fpsv.z=fpsv.z-dir;
		}
		//move mouse right
		if(px>oldx)
		{
			//move look position right
			fpsv.y=fpsv.y-dir;
		}
		//move mouse left
		if(px<oldx)
		{
			//move look position left
			fpsv.y=fpsv.y+dir;
		}
		//set old mouse position to new mouse position
		oldx=px;
		oldy=py;
	}
	//Press X on keyboard or Back on XBOX controller
	if(GetAsyncKeyState(0x58) || Player1->GetState().Gamepad.wButtons &  XINPUT_GAMEPAD_BACK)
	{
		//Resets the view point if you get lost
		fpsv.z=0;
		fpsv.y=0;
	}

	return fpsv;
}