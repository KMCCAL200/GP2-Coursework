#include "CameraComponent.h"
#include "Transform.h"
#include "GameObject.h"
#include "FPSMove.h"
#define _XM_NO_INTRINSICS_
#include <xnamath.h>
void CameraComponent::update()
{
	Transform transf = m_pOwnerGameObject->getTransform();
	XMFLOAT3 position = transf.getPosition();
	m_View=XMMatrixLookAtLH(XMLoadFloat3(&position),XMLoadFloat3(&m_LookAt),XMLoadFloat3(&m_Up));
    m_Projection=XMMatrixPerspectiveFovLH(m_FOV,m_AspectRatio,m_Near,m_Far);
	XMFLOAT3 currentfps = transf.getPosition();
	XMFLOAT3 newfps = FPSMove().movement(currentfps);
	m_pOwnerGameObject->getTransform().setPosition(newfps.x,newfps.y,newfps.z);
}