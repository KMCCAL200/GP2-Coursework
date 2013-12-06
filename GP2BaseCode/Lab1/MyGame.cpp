#include "MyGame.h"

bool MyGame::initGame()
{
	CubeVisualComponent *pCube=new CubeVisualComponent();
	pCube->create(m_pRenderer);
	
	Material *pMaterial=new Material();
	pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
	pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);

	DirectionLightComponent *pDirLight = new  DirectionLightComponent();

	GameObject *pTestObj=new GameObject();
	pTestObj->setName("TestObject");
	pTestObj->addComponent(pCube);
	pTestObj->addComponent(pMaterial);
	pTestObj->addComponent(pDirLight);

	pCube->createVertexLayout(m_pRenderer);
	
	pTestObj->getTransfrom().setPosition(-0.5f,0.0f,1.0f);

	m_GameObjectList.push_back(pTestObj);
	

	CubeVisualComponent *pCube2=new CubeVisualComponent();
	pCube2->create(m_pRenderer);

	Material *pMaterial1=new Material();
	pMaterial1->loadEffect("Effects/Texture.fx",m_pRenderer);

	GameObject *pTestObj2=new GameObject();
	pTestObj2->setName("TestObject2");
	pTestObj2->addComponent(pCube2);
	pTestObj2->addComponent(pMaterial1);



	CameraComponent *pCamera = new CameraComponent();

	pCamera->setLook(0.0f,0.0f,0.0f);
        pCamera->setFOV(m_GameOptionDesc.width/m_GameOptionDesc.height);

	GameObject *pTestCamera=new GameObject();
	pTestCamera->setName("MainCamera");
	pTestCamera->addComponent(pCamera);
	setMainCamera(pCamera);
	
	m_GameObjectList.push_back(pTestCamera);

	pCube2->createVertexLayout(m_pRenderer);
	
	pTestObj2->getTransfrom().setPosition(2.0f,0.0f,1.0f);

	m_GameObjectList.push_back(pTestObj2);
	
	return true;
}