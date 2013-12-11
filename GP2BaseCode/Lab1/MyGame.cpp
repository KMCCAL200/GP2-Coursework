#include "MyGame.h"

bool MyGame::initGame()
{

	//===============================================Test Object
	CubeVisualComponent *pCube=new CubeVisualComponent();
	pCube->create(m_pRenderer);

	Material *pMaterial=new Material();
	//pMaterial->loadEffect("Effects/DirectionalLight.fx",m_pRenderer);

	pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
	pMaterial->loadDiffuseTexture("Textures/ground1_color.jpg",m_pRenderer);
	//pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
	DirectionLightComponent *pDirLight = new  DirectionLightComponent();

	GameObject *pTestObj=new GameObject();
	pTestObj->setName("TestObject");
	pTestObj->addComponent(pCube);
	pTestObj->addComponent(pMaterial);
	pTestObj->addComponent(pDirLight);
	pCube->createVertexLayout(m_pRenderer);

	pTestObj->getTransform().setPosition(0.0f,0.0f,0.0f);
	pTestObj->getTransform().setScale(1.0f,1.0f,1.0f);

	m_GameObjectList.push_back(pTestObj);

	//==================================================CAMERA
	CameraComponent *pCameraComp=new CameraComponent();
	pCameraComp->setLook(0.0f,0.0f,0.0f);
	pCameraComp->setFOV(m_GameOptionDesc.width/m_GameOptionDesc.height);
	//Create Camera
	GameObject *pCameraGO=new GameObject();
	pCameraGO->setName("MainCamera");
	pCameraGO->addComponent(pCameraComp);
	setMainCamera(pCameraComp);
	pCameraGO->getTransform().setPosition(0.0f,0.0f,10.0f);

	m_GameObjectList.push_back(pCameraGO);

	//==============================AXE MODEL
	GameObject *pAxe = m_ModelLoader.loadModelFromFile("Models/1h_axe.fbx",m_pRenderer);
	pAxe->setName("One Handed Axe");
	
	
	//pAxe->addComponent(pDirLight);
	
	for(GameObject::ChildrenGameObjectsIter iter=pAxe->getFirstChild();iter!=pAxe->getLastChild();iter++)
	{

		iter->second->getTransform().setPosition(2.0f,0.0f,0.0f);
		iter->second->getTransform().setScale(0.1f,0.1f,0.1f);
		iter->second->getTransform().setRotation(1.0f,1.0f,1.0f);

		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/1h_axe.BMP",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

		pVisual->createVertexLayout(m_pRenderer);

	}

	//m_GameObjectList.push_back(pAxe);
	//===================================
	GameObject *pCar = m_ModelLoader.loadModelFromFile("Models/armoredrecon.fbx",m_pRenderer);
	pCar->setName("Armored Recon");
	//pAxe->addComponent(pDirLight);
	for(GameObject::ChildrenGameObjectsIter iter=pCar->getFirstChild();iter!=pCar->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(0.0f,-1.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		iter->second->getTransform().setRotation(-3.0f,0.0f,0.0f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/armoredrecon_diff.png",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

		pVisual->createVertexLayout(m_pRenderer);

	}
	//m_GameObjectList.push_back(pCar);
	//================================================Building
	/*GameObject *pBuilding = m_ModelLoader.loadModelFromFile("Models/armorstand.fbx",m_pRenderer);
	pAxe->setName("Building");
		for(GameObject::ChildrenGameObjectsIter iter=pBuilding->getFirstChild();iter!=pBuilding->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(0.0f,0.0f,0.0f);
		iter->second->getTransform().setScale(0.4f,0.4f,0.4f);
		iter->second->getTransform().setRotation(0.0f,0.0f,0.0f);
		//iter->second->addComponent(pDirLight);
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		//pMaterial->loadDiffuseTexture("Textures/armoredrecon.png",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

		pVisual->createVertexLayout(m_pRenderer);

	}
	m_GameObjectList.push_back(pBuilding);*/


	


	return true;
}