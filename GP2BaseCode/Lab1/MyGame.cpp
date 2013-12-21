#include "MyGame.h"

bool MyGame::initGame()
{
	//===============================================Test Object
	//CubeVisualComponent *pCube=new CubeVisualComponent();
	//pCube->create(m_pRenderer);

	Material *pMaterial=new Material();
	////pMaterial->loadEffect("Effects/DirectionalLight.fx",m_pRenderer);

	//pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
	//pMaterial->loadDiffuseTexture("Textures/ground1_color.jpg",m_pRenderer);
	////pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
	DirectionLightComponent *pDirLight = new  DirectionLightComponent();

	//GameObject *pTestObj=new GameObject();
	//pTestObj->setName("TestObject");
	//pTestObj->addComponent(pCube);
	//
	//pTestObj->addComponent(pMaterial);
	//pTestObj->addComponent(pDirLight);
	//pCube->createVertexLayout(m_pRenderer);

	//pTestObj->getTransform().setPosition(0.0f,0.0f,0.0f);
	//pTestObj->getTransform().setScale(1.0f,1.0f,1.0f);

	//m_GameObjectList.push_back(pTestObj);

	//============================================SkyBox - MD
	//Create Skybox object
	//GameObject *pSkyBox = m_ModelLoader.loadModelFromFile("SkyBox/cube2.fbx", m_pRenderer);
	//pSkyBox->setName("SkyBox");


	//for(GameObject::ChildrenGameObjectsIter iter=pSkyBox->getFirstChild();iter!=pSkyBox->getLastChild();iter++)
	//{
	//	//Add cube texture to cube mesh
	//	pMaterial = new Material();
	//	pMaterial->loadCubeTexture(m_pRenderer);
	//	//Load Skybox effect
	//	pMaterial->loadEffect("Effects/SkyBox.fx",m_pRenderer);
	//	
	//	pSkyBox->addComponent(pMaterial);
	//	
	//	VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

	//	pVisual->createVertexLayout(m_pRenderer);
	//}

	////Set position to center, should be tied to camera
	//pSkyBox->getTransform().setPosition(0.0f,0.0f,0.0f);
	//m_GameObjectList.push_back(pSkyBox);

	//==============================AXE MODEL
	GameObject *pGround = m_ModelLoader.loadModelFromFile("Models/Ground.fbx",m_pRenderer);
	pGround->setName("Ground");

	XMFLOAT3 pos;
	XMFLOAT3 rot;
	XMFLOAT3 scale;

	//positionObject(pAxe);

	for(GameObject::ChildrenGameObjectsIter iter=pGround->getFirstChild();iter!=pGround->getLastChild();iter++)
	{

		//pos = iter->second->getTransform().getPosition();
		//rot = iter->second->getTransform().getRotation();
		//scale = iter->second->getTransform().getScale();

		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/ground1_color.jpg",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

		pVisual->createVertexLayout(m_pRenderer);

	}
	
	//pGround->getTransform().setPosition(pos.x, pos.y,pos.z);
	//pGround->getTransform().setRotation(rot.x,rot.y,rot.z);
	//pGround->getTransform().setScale(scale.x,scale.y,scale.z);
	//pGround->addComponent(pDirLight);
	m_GameObjectList.push_back(pGround);

	//===================================
	GameObject *pBuilding1 = m_ModelLoader.loadModelFromFile("Models/Building12.fbx",m_pRenderer);
	pBuilding1->setName("Building1");
	//positionObject(pBuilding1);

	for(GameObject::ChildrenGameObjectsIter iter=pBuilding1->getFirstChild();iter!=pBuilding1->getLastChild();iter++)
	{
		//pos = iter->second->getTransform().getPosition();
		//rot = iter->second->getTransform().getRotation();
		//scale = iter->second->getTransform().getScale();
		
		pMaterial=new Material();
		//pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		//pMaterial->loadDiffuseTexture("Textures/bricks9_color.jpg",m_pRenderer);
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

		pVisual->createVertexLayout(m_pRenderer);

	}
	/*pBuilding1->getTransform().setPosition(pos.x,pos.y,pos.z);
	pBuilding1->getTransform().setRotation(rot.x,rot.y,rot.z);*/
	//pBuilding1->getTransform().setScale(scale.x*100,scale.y*100,scale.z*100);
	//pBuilding1->getTransform().setScale(scale.x,scale.y,scale.z);
	m_GameObjectList.push_back(pBuilding1);

	//================================================Building
	GameObject *pWall = m_ModelLoader.loadModelFromFile("Models/Wall2.fbx",m_pRenderer);
	pWall->setName("Wall");

	////positionObject(pWall);

	for(GameObject::ChildrenGameObjectsIter iter=pWall->getFirstChild();iter!=pWall->getLastChild();iter++)
	{
	//	pos = iter->second->getTransform().getPosition();
	//	rot = iter->second->getTransform().getRotation();
	//	scale = iter->second->getTransform().getScale();
	//	
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
	//	//pMaterial->loadDiffuseTexture("Textures/armoredrecon.png",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

		pVisual->createVertexLayout(m_pRenderer);

	}
	
	pWall->getTransform().setPosition(pos.x,pos.y,pos.z);
	pWall->getTransform().setRotation(rot.x,rot.y,rot.z);
	pWall->getTransform().setScale(scale.x,scale.y,scale.z);
	//m_GameObjectList.push_back(pWall);
	////=============================================================
	//
	//GameObject *pArmourStand = m_ModelLoader.loadModelFromFile("Models/ArmourStand.fbx",m_pRenderer);
	//pArmourStand->setName("Armour Stand");

	////positionObject(pArmourStand);
	//	for(GameObject::ChildrenGameObjectsIter iter=pArmourStand->getFirstChild();iter!=pArmourStand->getLastChild();iter++)
	//{
	//	pos = iter->second->getTransform().getPosition();
	//	rot = iter->second->getTransform().getRotation();
	//	scale = iter->second->getTransform().getScale();
	//	
	//	pMaterial=new Material();
	//	pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
	//
	//	iter->second->addComponent(pMaterial);

	//	VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

	//	pVisual->createVertexLayout(m_pRenderer);

	//}
	//
	//pArmourStand->getTransform().setPosition(pos.x,pos.y,pos.z);
	//pArmourStand->getTransform().setRotation(rot.x,rot.y,rot.z);
	//pArmourStand->getTransform().setScale(scale.x,scale.y,scale.z);
	//m_GameObjectList.push_back(pArmourStand);
	////============================
	//	GameObject *pTestBox = m_ModelLoader.loadModelFromFile("Models/TestBox.fbx",m_pRenderer);
	//pTestBox->setName("Test Box");

	////positionObject(pArmourStand);
	//	for(GameObject::ChildrenGameObjectsIter iter=pTestBox->getFirstChild();iter!=pTestBox->getLastChild();iter++)
	//{
	//	pos = iter->second->getTransform().getPosition();
	//	rot = iter->second->getTransform().getRotation();
	//	scale = iter->second->getTransform().getScale();
	//	
	//	pMaterial=new Material();
	//	pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
	//
	//	iter->second->addComponent(pMaterial);

	//	VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));

	//	pVisual->createVertexLayout(m_pRenderer);

	//}
	//
	//pTestBox->getTransform().setPosition(pos.x,pos.y,pos.z);
	//pTestBox->getTransform().setRotation(rot.x,rot.y,rot.z);
	//pTestBox->getTransform().setScale(scale.x,scale.y,scale.z);
	//m_GameObjectList.push_back(pTestBox);
	//============================




	/*
	(0.0f,0.0f,5.0f);
	pCameraComp->setLook(15.0f,0.0f,-35.0f);
	pCameraGO->getTransform().setPosition(15.0f,0.0f,-40.0f);
	pCameraGO->getTransform().setPosition(140.0f,0.0f,10.0f);
	*/




		//==================================================CAMERA
		//Create camera component
	CameraComponent *pCameraComp=new CameraComponent();
	//set start look at position
	pCameraComp->setLook(15.0f,0.0f,-39.9f);
	//set the field of view
	pCameraComp->setFOV(m_GameOptionDesc.width/m_GameOptionDesc.height);
	//Create camera object
	GameObject *pCameraGO=new GameObject();
	pCameraGO->setName("MainCamera");
	//Add camera component to camera object
	pCameraGO->addComponent(pCameraComp);
	setMainCamera(pCameraComp);
	//Start position of the camera
	pCameraGO->getTransform().setPosition(15.0f,0.0f,-40.0f);
	//Add the camera to the game world
	m_GameObjectList.push_back(pCameraGO);



	return true;
}


//void MyGame::positionObject(GameObject *pObjIn){
//	
//	XMFLOAT3 pos;
//	XMFLOAT3 rot;
//	XMFLOAT3 scale;
//
//	for(GameObject::ChildrenGameObjectsIter iter=pObjIn->getFirstChild();iter!=pObjIn->getLastChild();iter++)
//	{
//		pos = iter->second->getTransform().getPosition();
//		rot = iter->second->getTransform().getRotation();
//		scale = iter->second->getTransform().getScale();
//		
//		//pMaterial=new Material();
//		//pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
//	
//		//iter->second->addComponent(pMaterial);
//
//		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
//
//		pVisual->createVertexLayout(m_pRenderer);
//
//	}
//	
//	pObjIn->getTransform().setPosition(pos.x,pos.y,pos.z);
//	pObjIn->getTransform().setRotation(rot.x,rot.y,rot.z);
//	pObjIn->getTransform().setScale(scale.x,scale.y,scale.z);
//}