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
	pCameraGO->getTransform().setPosition(10.0f,400.0f,0.0f);
	
	m_GameObjectList.push_back(pCameraGO);
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