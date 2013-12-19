//#pragma once
//
//#include "GameObject.h"
//#include <vector>
//
//using namespace std;
//
//class ObjectManager{
//public:
//	ObjectManager(){};
//	~ObjectManager(){clear();};
//
//	void add(const string& name, GameObject* object);
//	GameObject* get(const string& name);
//	//=======================
//	void setPosition(const string& name, XMFLOAT3 position);
//	XMFLOAT3 getPosition(const string& name);
//	void clear();
//
//private:
//	map<const string,GameObject*> objects;
//	map<const string,XMFLOAT3> positions;
//	vector <XMFLOAT3> position;
//};