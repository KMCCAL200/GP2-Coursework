#pragma once
#include "VisualComponent.h"
#include <string>
#include <map>

using namespace std;

class ModelManager{
public:
	ModelManager(){};
	~ModelManager(){clear();};

	void add(const string& name, VisualComponent* model);
	VisualComponent* get(const string& name);
	void setPosition(const string& name, XMFLOAT3 position);
	XMFLOAT3 getPosition(const string& name);
	void clear();

private:
	map<const string,VisualComponent*> models;
	map<const string,XMFLOAT3> positions;
};