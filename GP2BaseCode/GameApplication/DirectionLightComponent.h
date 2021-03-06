#pragma once

#include "LightComponent.h"

class DirectionLightComponent:public LightComponent
{
public:

	DirectionLightComponent()
	{
	m_Name = "DirectionLight";
	 m_LightDirection=XMFLOAT3(0.0f,0.0f,-1.0f);
	};

	~DirectionLightComponent(){};

	void setDirection(float x, float y, float z)
	{
		m_LightDirection = XMFLOAT3(x,y,z);
	};

	XMFLOAT3& getDirection()
	{
		return m_LightDirection;
	};

private:
	XMFLOAT3 m_LightDirection;  //This represents the diffuse direction of the light

};