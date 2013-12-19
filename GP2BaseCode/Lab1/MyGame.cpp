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

	//*****CAMERA Kerri McCallum's code*****
	//Create camera component
	CameraComponent *pCameraComp=new CameraComponent();
	//set start look at position
	pCameraComp->setLook(0.0f,0.0f,5.0f);
	//set the field of view
	pCameraComp->setFOV(m_GameOptionDesc.width/m_GameOptionDesc.height);
	//Create camera object
	GameObject *pCameraGO=new GameObject();
	pCameraGO->setName("MainCamera");
	//Add camera component to camera object
	pCameraGO->addComponent(pCameraComp);
	setMainCamera(pCameraComp);
	//Start position of the camera
	pCameraGO->getTransform().setPosition(140.0f,0.0f,10.0f);
	//Add the camera to the game world
	m_GameObjectList.push_back(pCameraGO);
	//*****End Kerris code*****

	//==============================AXE MODEL
	GameObject *pAxe = m_ModelLoader.loadModelFromFile("Models/Ground.fbx",m_pRenderer);
	pAxe->setName("One Handed Axe");
	
	XMFLOAT3 pos;
	XMFLOAT3 rot;
	XMFLOAT3 scale;
	for(GameObject::ChildrenGameObjectsIter iter=pAxe->getFirstChild();iter!=pAxe->getLastChild();iter++)
	{
		pos = iter->second->getTransform().getPosition();
		rot = iter->second->getTransform().getRotation();
		scale = iter->second->getTransform().getScale();
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/ground1_color.jpg",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

		pVisual->createVertexLayout(m_pRenderer);

	}
	pAxe->getTransform().setPosition(pos.x, pos.y,pos.z);
	pAxe->getTransform().setRotation(rot.x,rot.y,rot.z);
	pAxe->getTransform().setScale(scale.x,scale.y,scale.z);
	m_GameObjectList.push_back(pAxe);
	GameObject *pCar = m_ModelLoader.loadModelFromFile("Models/Building1.fbx",m_pRenderer);
	pCar->setName("Armored Recon");
	for(GameObject::ChildrenGameObjectsIter iter=pCar->getFirstChild();iter!=pCar->getLastChild();iter++)
	{
		pos = iter->second->getTransform().getPosition();
		rot = iter->second->getTransform().getRotation();
		scale = iter->second->getTransform().getScale();
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

		pVisual->createVertexLayout(m_pRenderer);

	}
	pCar->getTransform().setPosition(pos.x,pos.y,pos.z);
	pCar->getTransform().setRotation(rot.x,rot.y,rot.z);
	pCar->getTransform().setScale(scale.x,scale.y,scale.z);
	m_GameObjectList.push_back(pCar);
	return true;
}