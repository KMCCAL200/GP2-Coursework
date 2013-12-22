//This File is Kerri McCallums work
#include "DebugMove.h"
//Moves the camera without the constraints of the world
//Holds old mouse position
float oldz=-100;
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
		fps.z=fps.z+dir;
	}
	//Move stick left or press left arrow on keyboard or d-pad
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT || GetAsyncKeyState(VK_LEFT) || Player1->GetState().Gamepad.sThumbLX < -10000)
	{
		//move the camera left
		fps.z=fps.z-dir;
	}
	//press page up on keyboard or right trigger
	if(Player1->GetState().Gamepad.bRightTrigger || GetAsyncKeyState(VK_PRIOR))
	{
		//move the camera up
		fps.y=fps.y+dir;
	}
	//press page down on keyboard or left trigger
	if(Player1->GetState().Gamepad.bLeftTrigger || GetAsyncKeyState(VK_NEXT))
	{
		//move the camera down
		fps.y=fps.y-dir;
	}
	//Press X on keyboard or Back on XBOX controller
	if(GetAsyncKeyState(0x58) || Player1->GetState().Gamepad.wButtons &  XINPUT_GAMEPAD_BACK)
	{
		//Resets the position if you get lost
		fps.x=300;
		fps.y=40;
		fps.z=0;
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
		fpsv.z=fpsv.z+dir;
	}
	//Move stick left or press left arrow on keyboard or d-pad
	if(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT || GetAsyncKeyState(VK_LEFT) || Player1->GetState().Gamepad.sThumbLX < -10000)
	{
		//move the view point left
		fpsv.z=fpsv.z-dir;
	}
	//press page up on keyboard or right trigger
	if(Player1->GetState().Gamepad.bRightTrigger || GetAsyncKeyState(VK_PRIOR))
	{
		//move view point up
		fpsv.y=fpsv.y+dir;
	}
	//press page down on keyboard or left trigger
	if(Player1->GetState().Gamepad.bLeftTrigger || GetAsyncKeyState(VK_NEXT))
	{
		//move view point down
		fpsv.y=fpsv.y-dir;
	}
	//******************LOOK USING RIGHT ANALOG STICK************************

	//Move stick down
	if(Player1->GetState().Gamepad.sThumbRY < -10000)
	{	
		//move look position up
		fpsv.y=fpsv.y+dir;
	}
	//Move stick up
	if(Player1->GetState().Gamepad.sThumbRY > 10000)
	{
		//move look position down
		fpsv.y=fpsv.y-dir;
	}
	//Move stick right
	if(Player1->GetState().Gamepad.sThumbRX > 10000)
	{
		//move look position right
		fpsv.z=fpsv.z+dir;
	}
	//Move stick left
	if(Player1->GetState().Gamepad.sThumbRX < -10000)
	{
		//move look position left
		fpsv.z=fpsv.z-dir;
	}
		//Hold down left mouse button and move mouse
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		dir = 3;
		//Finds where the pointer is on the screen
		POINT ptCursorPos;
		GetCursorPos(&ptCursorPos);
		//Sets the pointer position to look at position
		float pz = ptCursorPos.x;
		float py = ptCursorPos.y;
		//move mouse up
		if(py<oldy)
		{	
			//move look position up
			fpsv.y=fpsv.y+dir;
		}
		//move mouse down
		if(py>oldy)
		{
			//move look position down
			fpsv.y=fpsv.y-dir;
		}
		//move mouse right
		if(pz>oldz)
		{
			//move look position right
			fpsv.z=fpsv.z+dir;
		}
		//move mouse left
		if(pz<oldz)
		{
			//move look position left
			fpsv.z=fpsv.z-dir;
		}

		//set old mouse position to new mouse position
		oldz=pz;
		oldy=py;
	}
	//Press X on keyboard or Back on XBOX controller
	if(GetAsyncKeyState(0x58) || Player1->GetState().Gamepad.wButtons &  XINPUT_GAMEPAD_BACK)
	{
		//Resets the view point if you get lost
		fpsv.x=0;
		fpsv.y=-3;
		fpsv.z=3;
	}

	return fpsv;
}