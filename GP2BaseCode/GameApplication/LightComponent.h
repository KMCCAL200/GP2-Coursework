#pragma once

#include "GameComponent.h"



#include <Windows.h>
#define _XM_NO_INTRINSICS_
#include <xnamath.h>



class LightComponent:public GameComponent
{
public:

	LightComponent()
	{
	m_Name = "Light";
	 m_DiffuseColour=XMFLOAT4(0.8f,0.8f,0.8f,1.0f);
     m_SpecularColour=XMFLOAT4(1.0f,1.0f,1.0f,1.0f);
	};

	~LightComponent(){};


private:
	XMFLOAT4 m_DiffuseColour;     //This represents the diffuse colour of the light
	XMFLOAT4 m_SpecularColour;    //This represents the specular colour of the light

public:
	void setDiffuse(float r, float g, float b, float a)  //Set function
	{
		m_DiffuseColour = XMFLOAT4(r,g,b,a);
	}; 

	void setSpecular(float r, float g, float b, float a)  //Set function
	{
		m_SpecularColour = XMFLOAT4(r,g,b,a);
	};   

	XMFLOAT4& getDiffuse()   //get function
	{
	return m_DiffuseColour;
	};  

	XMFLOAT4& getSpecular()    //get function
	{
	return m_SpecularColour;
	};

};