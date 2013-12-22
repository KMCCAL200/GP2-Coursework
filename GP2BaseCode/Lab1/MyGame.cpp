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
		iter->second->getTransform().setPosition(-160.0f,-10.0f,30.0f);
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
		iter->second->getTransform().setPosition(-10.0f,10.0f,-30.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);
	}
	m_GameObjectList.push_back(pBench);
	////=============================================================Armour Stand
	GameObject *pArmourStand= m_ModelLoader.loadModelFromFile("Models/ArmourStand.fbx",m_pRenderer);
	pBench->setName("Armour_Stnad");

	for(GameObject::ChildrenGameObjectsIter iter=pArmourStand->getFirstChild();iter!=pArmourStand->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(-10.0f,-4.0f,10.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/g_1.BMP",m_pRenderer);
		//pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);
	}
	m_GameObjectList.push_back(pArmourStand);
	////====================================================================Anvil
	GameObject *pAnvil = m_ModelLoader.loadModelFromFile("Models/Anvil.fbx",m_pRenderer);
	pAnvil->setName("Anvil");

	for(GameObject::ChildrenGameObjectsIter iter=pAnvil->getFirstChild();iter!=pAnvil->getLastChild();iter++)
	{
		iter->second->getTransform().setPosition(-20.0f,-20.0f,40.0f);
		iter->second->getTransform().setRotation(-1.57079633f/2,0.0f,0.0f);
		iter->second->getTransform().setScale(1.0f,1.0f,1.0f);
		
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/m_3.BMP",m_pRenderer);
		//pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
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
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/bricks3_color.jpg",m_pRenderer);
		//pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
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
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/u_5.BMP",m_pRenderer);
		//pMaterial->loadEffect("Effects/Specular.fx",m_pRenderer);
		iter->second->addComponent(pMaterial);

		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);

	}
	m_GameObjectList.push_back(pWoodenBoard);


	return true;
}

