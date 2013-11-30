#pragma once

#include "GameComponent.h"

#include <windows.h>
#define _XM_NO_INTRINSICS_
#include <xnamath.h>

class CameraComponent:public GameComponent
{
public:
	CameraComponent()
	{
	};

	~CameraComponent()
	{
	}

	private:
	XMFLOAT3 m_LookAt;
	XMFLOAT3 m_Up;
	float m_FOV;
	float m_AspectRatio;
	float m_Near;
	float m_Far;

	XMMATRIX m_View;
	XMMATRIX m_Projection;

public:
//Set Functions
	void setLook(float x, float y, float z)
	{
		m_LookAt = XMFLOAT3(x,y,z);
	};

	void setUp(float x, float y, float z)
	{
		m_Up = XMFLOAT3(x,y,z);
	};

	void setFOV(float fov)
	{
		m_FOV = fov;
	};

	void setAspectRatio(float ratio)
	{
		m_AspectRatio = ratio;
	};

	void SetNearClip(float nearClip)
	{
		m_Near= nearClip;
	};

	void setFarClip(float farClip)
	{
		m_Far = farClip;
	};
	
	//Get Functions
	float getFOV()
	{
		return m_FOV;
	};

	float getAspectRatio()
	{
		return m_AspectRatio;
	};

	float GetNearClip()
	{
		return m_Near;
	};

	float getFarClip()
	{
		return m_Far;
	};
	
	XMFLOAT3& getLook()
	{
		return m_LookAt;
	};

	XMFLOAT3& getUp()
	{
		return m_Up;
	};

	XMMATRIX& getView()
	{
		return m_View;
	};

	XMMATRIX& getProjection()
	{
		return m_Projection;
	};

	//overridden from base class
	void update();

};
