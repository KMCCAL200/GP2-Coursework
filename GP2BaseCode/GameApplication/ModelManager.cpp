#include "ModelManager.h"

void ModelManager::add(const string& name, VisualComponent* model){
	
	if (models.find(name)==models.end()){
	
		models[name]=model;
	
	}
}
XMFLOAT3 ModelManager::getPosition(const string& name){
	return positions[name];
}
VisualComponent* ModelManager::get(const string& name){
	
	return models[name];
}
void ModelManager::setPosition(const string& name, XMFLOAT3 position){
	if (positions.find(name)==positions.end()){
	
		positions[name]=position;
	
	}
}
void ModelManager::clear(){
	
	map<const string,VisualComponent*>::iterator iter=models.begin();
	
	while(iter!=models.end())
	{
		if ((*iter).second)
		{
			delete (*iter).second;
			(*iter).second=NULL;
			iter=models.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	models.clear();
}