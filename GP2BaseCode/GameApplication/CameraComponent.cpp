#include "CameraComponent.h"
#include "Transform.h"
#include "GameObject.h"
#include "FPSMove.h"
#include "DebugMove.h"

//Is user using debug camera?
	bool debug = false;

void CameraComponent::update()
{
	CXBOXController* Player1;Player1 = new CXBOXController(1);
	//Current position of camera
	XMFLOAT3 position = m_pOwnerGameObject->getTransform().getPosition();
	//New positiomn of camera
	XMFLOAT3 newfps;

	//If the user presses the d key or left bumper the debug camera is active
	if(GetAsyncKeyState(0x44) || Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
	{debug = true;}
	//If the user presses the f key or right bumper the fps camera is active
	if(GetAsyncKeyState(0x46) || Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
	{debug = false;}


	if(debug==true)
	{//Debug Movement (without constraints)
		//New position
		newfps = DebugMove().cameraPos(position);
		//New look at point
		m_LookAt = DebugMove().lookAt(m_LookAt);
	}
	if(debug==false)
	{//FPS Movement (with constraints)
		//New position
		newfps = FPSMove().cameraPos(position);
		//New look at point
		m_LookAt = FPSMove().lookAt(m_LookAt,position);
	}
	//Build the view matrix using the new position and look at point of the camera
	m_View=XMMatrixLookAtLH(XMLoadFloat3(&position),XMLoadFloat3(&m_LookAt),XMLoadFloat3(&m_Up));
	//Build the projection matrix that determines what will be on the screen
	m_Projection=XMMatrixPerspectiveFovLH(m_FOV,m_AspectRatio,m_Near,m_Far);
	//Sets the cameras new position
	m_pOwnerGameObject->getTransform().setPosition(newfps.x,newfps.y,newfps.z);
}