#include "CameraComponent.h"
#include "Transform.h"
#include "GameObject.h"
#include "FPSMove.h"
#include "DebugMove.h"
#define _XM_NO_INTRINSICS_
#include <xnamath.h>
void CameraComponent::update()
{
	Transform transf = m_pOwnerGameObject->getTransform();
	XMFLOAT3 position = transf.getPosition();
	XMFLOAT3 newfps;
	bool debug = false;
	if(GetAsyncKeyState(VK_SHIFT)){debug = true;}
	if(GetAsyncKeyState(VK_SPACE)){debug = false;}

	
	if(debug==true)
	{
		//DebugMove
		newfps = DebugMove().cameraPos(position);
		m_LookAt = DebugMove().lookAt(m_LookAt);
	}
	if(debug==false)
	{
		newfps = FPSMove().cameraPos(position);
		m_LookAt = FPSMove().lookAt(m_LookAt,position);
	}

	m_View=XMMatrixLookAtLH(XMLoadFloat3(&position),XMLoadFloat3(&m_LookAt),XMLoadFloat3(&m_Up));
    m_Projection=XMMatrixPerspectiveFovLH(m_FOV,m_AspectRatio,m_Near,m_Far);
	m_pOwnerGameObject->getTransform().setPosition(newfps.x,newfps.y,newfps.z);
}