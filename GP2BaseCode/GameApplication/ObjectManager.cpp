//#include "ObjectManager.h"
//
//void ObjectManager::add(const string& name, GameObject* object){
//	
//	if (objects.find(name)==objects.end()){
//	
//		objects[name]=object;
//	
//	}
//}
//XMFLOAT3 ObjectManager::getPosition(const string& name){
//	return positions[name];
//}
//GameObject* ObjectManager::get(const string& name){
//	
//	return objects[name];
//}
//void ObjectManager::setPosition(const string& name, XMFLOAT3 position){
//	if (positions.find(name)==positions.end()){
//	
//		positions[name]=position;
//	
//	}
//}
//void ObjectManager::clear(){
//	
//	map<const string,GameObject*>::iterator iter=objects.begin();
//	
//	while(iter!=objects.end())
//	{
//		if ((*iter).second)
//		{
//			delete (*iter).second;
//			(*iter).second=NULL;
//			iter=objects.erase(iter);
//		}
//		else
//		{
//			iter++;
//		}
//	}
//
//	objects.clear();
//}