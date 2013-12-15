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
	
	pTestObj->getTransform().setPosition(0.0f,0.0f,0.0f);

	m_GameObjectList.push_back(pTestObj);


	//CAMERA
		CameraComponent *pCameraComp=new CameraComponent();
        pCameraComp->setLook(0.0f,0.0f,0.0f);
        pCameraComp->setFOV(m_GameOptionDesc.width/m_GameOptionDesc.height);
        GameObject *pCameraGO=new GameObject();
        pCameraGO->setName("MainCamera");
        pCameraGO->addComponent(pCameraComp);
        setMainCamera(pCameraComp);
        pCameraGO->getTransform().setPosition(-100.0f,0.0f,0.0f);

        m_GameObjectList.push_back(pCameraGO);
	
		//==============================Model
		GameObject *pAxe=m_ModelLoader.loadModelFromFile("Models/shield.fbx",m_pRenderer);
		
        for(GameObject::ChildrenGameObjectsIter iter=pAxe->getFirstChild();iter!=pAxe->getLastChild();iter++)
        {
                pMaterial=new Material();
                pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
                pMaterial->loadDiffuseTexture("Textures/shield.bmp",m_pRenderer);
                iter->second->addComponent(pMaterial);
                VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
                pVisual->createVertexLayout(m_pRenderer);
        }

        m_GameObjectList.push_back(pAxe);
		//===================================
	return true;
}