#include "FPSMove.h"
//Moves the camera within the constraints of the world
//Holds old mouse position
float oldPz=-100;
float oldPy=-100;

XMFLOAT3 FPSMove::cameraPos(XMFLOAT3 fps)
{	
	//***************MOVEMENT USING LEFT ANALOG STICK or D-PAD or KEYBOARD********************

	//Move stick up or press up arrow on keyboard or d-pad
	if(fps.x>-50 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP || GetAsyncKeyState(VK_UP) || Player1->GetState().Gamepad.sThumbLY > 10000))
	{
		//move the camera forward
		fps.x=fps.x-dir;
	}
	//Move stick down or press down arrow on keyboard or d-pad
	if(fps.x<350 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN || GetAsyncKeyState(VK_DOWN) || Player1->GetState().Gamepad.sThumbLY < -10000))
	{
		//move camera back
		fps.x=fps.x+dir;
	}  	
	//Move stick right or press right arrow on keyboard or d-pad
	if(fps.z<280 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT || GetAsyncKeyState(VK_RIGHT) || Player1->GetState().Gamepad.sThumbLX > 10000))
	{
		//move the camera right
		fps.z=fps.z+dir;
	}
	//Move stick left or press left arrow on keyboard or d-pad
	if(fps.z>-230 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT || GetAsyncKeyState(VK_LEFT) || Player1->GetState().Gamepad.sThumbLX < -10000))
	{
		//move the camera left
		fps.z=fps.z-dir;
	}
	//return updated position
	return fps;
}

XMFLOAT3 FPSMove::lookAt(XMFLOAT3 fpsv,XMFLOAT3 fps)
{		
	//***************MOVEMENT USING LEFT ANALOG STICK or D-PAD or KEYBOARD********************

	//Move stick up or press up arrow on keyboard or d-pad
	if(fps.x>-50 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP || GetAsyncKeyState(VK_UP) || Player1->GetState().Gamepad.sThumbLY > 10000))
	{
		//move the view point forward
		fpsv.x=fpsv.x-dir;
	}
	//Move stick down or press down arrow on keyboard or d-pad
	if(fps.x<350 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN || GetAsyncKeyState(VK_DOWN) || Player1->GetState().Gamepad.sThumbLY < -10000))
	{	
		//move view point back
		fpsv.x=fpsv.x+dir;
	}
	//Move stick right or press right arrow on keyboard or d-pad
	if(fps.z<280 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT || GetAsyncKeyState(VK_RIGHT) || Player1->GetState().Gamepad.sThumbLX > 10000))
	{
		//move the view point right
		fpsv.z=fpsv.z+dir;
	}
	//Move stick left or press left arrow on keyboard or d-pad
	if(fps.z>-230 & (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT || GetAsyncKeyState(VK_LEFT) || Player1->GetState().Gamepad.sThumbLX < -10000))
	{
		//move the view point left
		fpsv.z=fpsv.z-dir;
	}

	//******************LOOK WITH USING ANALOG STICK************************
	//Move stick down
	if(fpsv.y<200 & (Player1->GetState().Gamepad.sThumbRY < -10000))
	{	
		//move look position up
		fpsv.y=fpsv.y+dir;
	}
	//Move stick up
	if(fpsv.y>-200 & (Player1->GetState().Gamepad.sThumbRY > 10000))
	{
		//move look position down
		fpsv.y=fpsv.y-dir;
	}
	//Move stick right
	if(fpsv.z<260 & (Player1->GetState().Gamepad.sThumbRX > 10000))
	{
		//move look position right
		fpsv.z=fpsv.z+dir;
	}
	//Move stick left
	if(fpsv.z>-260 & (Player1->GetState().Gamepad.sThumbRX < -10000))
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
		if(fpsv.y<200 & py<oldPy)
		{	
			//move look position up
			fpsv.y=fpsv.y+dir;
		}
		//move mouse down
		if(fpsv.y>-200 & py>oldPy)
		{
			//move look position down
			fpsv.y=fpsv.y-dir;
		}
		//move mouse right
		if(fpsv.z<260 & pz>oldPz)
		{
			//move look position right
			fpsv.z=fpsv.z+dir;
		}
		//move mouse left
		if(fpsv.z>-260 & pz<oldPz)
		{
			//move look position left
			fpsv.z=fpsv.z-dir;
		}

		//set old mouse position to new mouse position
		oldPz=pz;
		oldPy=py;
	}
	//return updated look at point
	return fpsv;
}