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
	 m_DiffuseColour=XMCOLOR(0.8f,0.8f,0.8f,1.0f);
     m_SpecularColour=XMCOLOR(1.0f,1.0f,1.0f,1.0f);
	};

	~LightComponent(){};


private:
	XMCOLOR m_DiffuseColour;     //This represents the diffuse colour of the light
	XMCOLOR m_SpecularColour;    //This represents the specular colour of the light

public:
	void setDiffuse(float r, float g, float b, float a)  //Set function
	{
		m_DiffuseColour = XMCOLOR(r,g,b,a);
	}; 

	void setSpecular(float r, float g, float b, float a)  //Set function
	{
		m_SpecularColour = XMCOLOR(r,g,b,a);
	};   

	XMCOLOR& getDiffuse()   //get function
	{
	return m_DiffuseColour;
	};  

	XMCOLOR& getSpecular()    //get function
	{
	return m_SpecularColour;
	};

};