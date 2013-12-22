#include "MyGame.h"

bool MyGame::initGame()
{
<<<<<<< HEAD
	XMFLOAT3 fullScale = XMFLOAT3(1.0f,1.0f,1.0f);
	XMFLOAT3 halfScale = XMFLOAT3(0.5f,0.5f,0.5f);
=======
>>>>>>> origin/Kerri-camera-in-skybox
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

<<<<<<< HEAD
	//==================================================CAMERA
	CameraComponent *pCameraComp=new CameraComponent();
	pCameraComp->setLook(0.0f,0.0f,0.0f);
	pCameraComp->setFOV(m_GameOptionDesc.width/m_GameOptionDesc.height);
	//Create Camera
	GameObject *pCameraGO=new GameObject();
	pCameraGO->setName("MainCamera");
	pCameraGO->addComponent(pCameraComp);
	setMainCamera(pCameraComp);
	pCameraGO->getTransform().setPosition(300.0f,40.0f,0.0f);
	
	m_GameObjectList.push_back(pCameraGO);
	//============================================SkyBox - MD
	//Create Skybox object
	//GameObject *pSkyBox = m_ModelLoader.loadModelFromFile("SkyBox/cube2.fbx", m_pRenderer);
	//pSkyBox->setName("SkyBox");


	//for(GameObject::ChildrenGameObjectsIter iter=pSkyBox->getFirstChild();iter!=pSkyBox->getLastChild();iter++)
	//{

	//	iter->second->getTransform().setPosition(0.0f, 0.0f,0.0f);
	//	iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
	//	iter->second->getTransform().setScale(0.5f,0.5f,0.5f);
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

	//////Set position to center, should be tied to camera
	//
	//m_GameObjectList.push_back(pSkyBox);

	//==============================Ground
	GameObject *pGround = m_ModelLoader.loadModelFromFile("Models/Ground.fbx",m_pRenderer);
	pGround->setName("Ground");

	for(GameObject::ChildrenGameObjectsIter iter=pGround->getFirstChild();iter!=pGround->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(0.0f, 0.0f,0.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);

		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/stones5_color.jpg",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);
	}
	m_GameObjectList.push_back(pGround);

	//===================================Blacksmith House
	GameObject *pBuilding1 = m_ModelLoader.loadModelFromFile("Models/Building1.fbx",m_pRenderer);
	pBuilding1->setName("Building1");

	for(GameObject::ChildrenGameObjectsIter iter=pBuilding1->getFirstChild();iter!=pBuilding1->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(0.0f,20.0f,-58.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);

	}
	m_GameObjectList.push_back(pBuilding1);

	//================================================Bench
	GameObject *pBench = m_ModelLoader.loadModelFromFile("Models/Bench.fbx",m_pRenderer);
	pBench->setName("Bench");

	for(GameObject::ChildrenGameObjectsIter iter=pBench->getFirstChild();iter!=pBench->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(-200.0f,0.0f,0.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(0.5f,0.5f,0.5f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);
	}
	//m_GameObjectList.push_back(pBench);
	////=============================================================Armour Stand
	GameObject *pArmourStand= m_ModelLoader.loadModelFromFile("Models/ArmourStand.fbx",m_pRenderer);
	pBench->setName("Armour_Stnad");

	for(GameObject::ChildrenGameObjectsIter iter=pArmourStand->getFirstChild();iter!=pArmourStand->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(80.0f,0.0f,0.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(0.5f,0.5f,0.5f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);
	}
//	m_GameObjectList.push_back(pArmourStand);
	////====================================================================Anvil
	GameObject *pAnvil = m_ModelLoader.loadModelFromFile("Models/Anvil.fbx",m_pRenderer);
	pAnvil->setName("Anvil");

	for(GameObject::ChildrenGameObjectsIter iter=pAnvil->getFirstChild();iter!=pAnvil->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(60.0f,5.0f,-20.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);

	}
	m_GameObjectList.push_back(pAnvil);
	//=======================================================================2 Handed Axe
	GameObject *p2hAxe = m_ModelLoader.loadModelFromFile("Models/2hAxe.fbx",m_pRenderer);
	p2hAxe ->setName("2hAxe");

	for(GameObject::ChildrenGameObjectsIter iter=p2hAxe->getFirstChild();iter!=p2hAxe->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(60.0f,0.0f,0.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/2h_axe.BMP",m_pRenderer);
		//pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);

	}
	m_GameObjectList.push_back(p2hAxe);
		//=======================================================================Bridge
	GameObject *pBridge = m_ModelLoader.loadModelFromFile("Models/Bridge.fbx",m_pRenderer);
	pBridge->setName("Bridge");

	for(GameObject::ChildrenGameObjectsIter iter=pBridge->getFirstChild();iter!=pBridge->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(0.0f,-115.0f,270.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);

	}
	m_GameObjectList.push_back(pBridge);
			//=======================================================================Building2
	GameObject *pBuilding2 = m_ModelLoader.loadModelFromFile("Models/Building2.fbx",m_pRenderer);
	pBuilding2->setName("Building2");

	for(GameObject::ChildrenGameObjectsIter iter=pBuilding2->getFirstChild();iter!=pBuilding2->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(100.0f,20.0f,0.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(0.5f,0.5f,0.5f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);

	}
	//m_GameObjectList.push_back(pBuilding2);
			//=======================================================================Wall
	GameObject *pWall = m_ModelLoader.loadModelFromFile("Models/Wall.fbx",m_pRenderer);
	pWall->setName("Wall");

	for(GameObject::ChildrenGameObjectsIter iter=pWall->getFirstChild();iter!=pWall->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(0.0f,0.0f,-150.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);

	}
	m_GameObjectList.push_back(pWall);
			//=======================================================================Wall
	GameObject *pWoodenBoard = m_ModelLoader.loadModelFromFile("Models/WoodBoard.fbx",m_pRenderer);
	pWoodenBoard->setName("WoodenBoard");

	for(GameObject::ChildrenGameObjectsIter iter=pWoodenBoard->getFirstChild();iter!=pWoodenBoard->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(80.0f,20.0f,-50.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);

	}
	m_GameObjectList.push_back(pWoodenBoard);


	return true;
}
=======
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
>>>>>>> origin/Kerri-camera-in-skybox
