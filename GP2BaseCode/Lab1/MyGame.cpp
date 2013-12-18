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

	//m_GameObjectList.push_back(pTestObj);

	//==================================================CAMERA
	CameraComponent *pCameraComp=new CameraComponent();
	pCameraComp->setLook(0.0f,0.0f,0.0f);
	pCameraComp->setFOV(m_GameOptionDesc.width/m_GameOptionDesc.height);
	//Create Camera
	GameObject *pCameraGO=new GameObject();
	pCameraGO->setName("MainCamera");
	pCameraGO->addComponent(pCameraComp);
	setMainCamera(pCameraComp);
	pCameraGO->getTransform().setPosition(140.0f,0.0f,10.0f);
	
	m_GameObjectList.push_back(pCameraGO);

	//==============================AXE MODEL
	GameObject *pAxe = m_ModelLoader.loadModelFromFile("Models/Ground.fbx",m_pRenderer);
	pAxe->setName("One Handed Axe");
	
	
	//pAxe->addComponent(pDirLight);
	XMFLOAT3 pos;
	XMFLOAT3 rot;
	XMFLOAT3 scale;
	for(GameObject::ChildrenGameObjectsIter iter=pAxe->getFirstChild();iter!=pAxe->getLastChild();iter++)
	{

		pos = iter->second->getTransform().getPosition();
		rot = iter->second->getTransform().getRotation();
		scale = iter->second->getTransform().getScale();
		
		
		//iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		//iter->second->getTransform().setRotation(0.0f,0.0f,0.0f);
		

		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/ground1_color.jpg",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

		pVisual->createVertexLayout(m_pRenderer);

	}
	//objectManager.add("HandAxe", pAxe);
	pAxe->getTransform().setPosition(pos.x, pos.y,pos.z);
	pAxe->getTransform().setRotation(rot.x,rot.y,rot.z);
	pAxe->getTransform().setScale(scale.x,scale.y,scale.z);
	m_GameObjectList.push_back(pAxe);
//	pAxe = m_ModelLoader.loadModelFromFile("Models/boxex.fbx",m_pRenderer);
	//===================================
	GameObject *pCar = m_ModelLoader.loadModelFromFile("Models/Building1.fbx",m_pRenderer);
	pCar->setName("Armored Recon");
	//pAxe->addComponent(pDirLight);
	for(GameObject::ChildrenGameObjectsIter iter=pCar->getFirstChild();iter!=pCar->getLastChild();iter++)
	{
		pos = iter->second->getTransform().getPosition();
		rot = iter->second->getTransform().getRotation();
		scale = iter->second->getTransform().getScale();
		//iter->second->getTransform().setPosition(0.0f,-1.0f,0.0f);
		//iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		//iter->second->getTransform().setRotation(0.0f,0.0f,0.0f);
		
		pMaterial=new Material();
		//pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		//pMaterial->loadDiffuseTexture("Textures/bricks9_color.jpg",m_pRenderer);
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		//pMaterial->loadDiffuseTexture("Textures/armoredrecon_diff.png",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

		pVisual->createVertexLayout(m_pRenderer);

	}
	pCar->getTransform().setPosition(pos.x,pos.y,pos.z);
	pCar->getTransform().setRotation(rot.x,rot.y,rot.z);
	pCar->getTransform().setScale(scale.x,scale.y,scale.z);
	m_GameObjectList.push_back(pCar);
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