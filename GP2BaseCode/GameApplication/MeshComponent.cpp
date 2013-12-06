#include "MeshComponent.h"
#include "../D3D10Renderer/Vertex.h"
#include "../D3D10Renderer/D3D10Renderer.h"
#include <iostream>

using namespace std;
bool MeshComponent::create(IRenderer * pRenderer)
{

	FILE * file = fopen("Models/shield_deco3.obj", "r");
	if( file == NULL ){
		printf("Impossible to open the file !\n");
		return false;
	}
	XMFLOAT3 temp_vertices;

	int i=0;
	int n=-1;
	vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	Vertex  temp_uvs;
	Vertex  temp_normals;

	Vertex verts[40];

	int indices[172];

	while(1){
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader

		if ( strcmp( lineHeader, "v" ) == 0 )
		{
			fscanf(file, "%f %f %f\n", &verts[i].position.x, &verts[i].position.y, &verts[i].position.z );
			i++;
		}
		else if ( strcmp( lineHeader, "vn" ) == 0 )
		{
			fscanf(file, "%f %f %f\n", &temp_normals.normal.x, &temp_normals.normal.y, &temp_normals.normal.z );

		}
		else if ( strcmp( lineHeader, "f" ) == 0 )
		{
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
			
			indices[n++]=vertexIndex[0];
			indices[n++]=vertexIndex[1];
			indices[n++]=vertexIndex[2];

			if (matches != 9)
			{
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return false;
			}
		}
	}
	m_iNoVerts=40;
	m_iNoIndices=172;
	D3D10Renderer *pD3D10Renderer=static_cast<D3D10Renderer*>(pRenderer);

	m_pVertexBuffer=pD3D10Renderer->createVertexBuffer(m_iNoVerts,verts); 
	m_pIndexBuffer=pD3D10Renderer->createIndexBuffer(m_iNoIndices,indices);

	return true;
}