#include "MyGame.h"

bool MyGame::initGame()
{
	/*CubeVisualComponent *pCube=new CubeVisualComponent();
	pCube->create(m_pRenderer);
	
	Material *pMaterial=new Material();
	pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
	pMaterial->loadDiffuseTexture("Textures/sword2_C.bmp",m_pRenderer);
	pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
	DirectionLightComponent *pDirLight = new  DirectionLightComponent();
	

	GameObject *pTestObj=new GameObject();
	pTestObj->setName("TestObject");
	pTestObj->addComponent(pCube);
	pTestObj->addComponent(pMaterial);
	pTestObj->addComponent(pDirLight);
	pCube->createVertexLayout(m_pRenderer);
	
	pTestObj->getTransform().setPosition(-0.5f,0.0f,1.0f);

	m_GameObjectList.push_back(pTestObj);*/


	//CAMERA
		CameraComponent *pCameraComp=new CameraComponent();
        pCameraComp->setLook(0.0f,0.0f,0.0f);
        pCameraComp->setFOV(m_GameOptionDesc.width/m_GameOptionDesc.height);
        //Create Camera
        GameObject *pCameraGO=new GameObject();
        pCameraGO->setName("MainCamera");
        pCameraGO->addComponent(pCameraComp);
        setMainCamera(pCameraComp);
        pCameraGO->getTransform().setPosition(100.5f,200.0f,-200.0f);

        m_GameObjectList.push_back(pCameraGO);
		Material *pMaterial=new Material();
		DirectionLightComponent *pDirLight = new  DirectionLightComponent();
	
		//==============================Model
		GameObject *pAxe=m_ModelLoader.loadModelFromFile("Models/2h_axe.fbx",m_pRenderer);
		
        for(GameObject::ChildrenGameObjectsIter iter=pAxe->getFirstChild();iter!=pAxe->getLastChild();iter++)
        {
                pMaterial=new Material();
				pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
               // pMaterial->loadEffect("Effects/BumpMapping.fx",m_pRenderer);
                pMaterial->loadDiffuseTexture("Textures/2h_axe.BMP",m_pRenderer);
				pMaterial->loadBumpTexture("BumpTextures/2h_axeN.bmp",m_pRenderer);
				iter->second->addComponent(pDirLight);
                iter->second->addComponent(pMaterial);
                VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
                pVisual->createVertexLayout(m_pRenderer);
        }
		//pAxe->addComponent(pDirLight);
        m_GameObjectList.push_back(pAxe);

		
	

		
		//===================================
	return true;
}