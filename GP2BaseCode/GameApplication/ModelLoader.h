#pragma once

#define FBXSDK_NEW_API

#include "ModelManager.h"
#include <string>

#include "..\Renderer\Renderer.h"

class GameObject;

using namespace std;


class ModelLoader
{
public:
        ModelLoader(){};
        ~ModelLoader(){};

		void computeTangents(Vertex *pVerts,int vertexCount); 
        GameObject * loadModelFromFile(const string& filename, IRenderer *pRenderer);
private:
        GameObject * loadFbxModelFromFile(const string& filename, IRenderer *pRenderer);
		ModelManager modelManager;
};