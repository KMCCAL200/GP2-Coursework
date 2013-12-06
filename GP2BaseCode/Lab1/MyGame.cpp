#include "MyGame.h"

bool MyGame::initGame()
{
	//CubeVisualComponent *pCube=new CubeVisualComponent();
	//pCube->create(m_pRenderer);
	//
	//Material *pMaterial=new Material();
	//pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
	//pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
	//DirectionLightComponent *pDirLight = new  DirectionLightComponent();

	//GameObject *pTestObj=new GameObject();
	//pTestObj->setName("TestObject");
	//pTestObj->addComponent(pCube);
	//pTestObj->addComponent(pMaterial);
	//pTestObj->addComponent(pDirLight);
	//pCube->createVertexLayout(m_pRenderer);
	//
	//pTestObj->getTransform().setPosition(-0.5f,0.0f,1.0f);

	//m_GameObjectList.push_back(pTestObj);





	
	MeshComponent *pCube=new MeshComponent();
	pCube->create(m_pRenderer);
	
	Material *pMaterial=new Material();
	//pMaterial->loadEffect("Effects/Transform.fx",m_pRenderer);
	pMaterial->loadDiffuseTexture("Models/shield3.bmp",m_pRenderer);
	pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
	GameObject *pTestObj=new GameObject();
	pTestObj->setName("TestObject");
	pTestObj->addComponent(pCube);
	pTestObj->addComponent(pMaterial);

	pCube->createVertexLayout(m_pRenderer);
	
	pTestObj->getTransform().setPosition(0.5f,1.0f,1.0f);

	m_GameObjectList.push_back(pTestObj);




	//CAMERA
		CameraComponent *pCameraComp=new CameraComponent();
        pCameraComp->setLook(0.0f,0.0f,0.0f);
        pCameraComp->setFOV(m_GameOptionDesc.width/m_GameOptionDesc.height);
        //Create Camera
        GameObject *pCameraGO=new GameObject();
        pCameraGO->setName("MainCamera");
        pCameraGO->addComponent(pCameraComp);
        setMainCamera(pCameraComp);
        pCameraGO->getTransform().setPosition(-100.0f,140.0f,40.0f);

        m_GameObjectList.push_back(pCameraGO);
	
	return true;
}