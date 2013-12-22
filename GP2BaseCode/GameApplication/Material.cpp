#include "Material.h"

#include "../D3D10Renderer/D3D10Renderer.h"

bool Material::loadEffect(const string& filename,IRenderer * pRenderer)
{
	D3D10Renderer *pD3D10Renderer=static_cast<D3D10Renderer*>(pRenderer);

	m_pEffect=pD3D10Renderer->loadEffectFromFile(filename.c_str());
	if (!m_pEffect)
	{
		return false;
	}
	m_pCurrentTechnique=m_pEffect->GetTechniqueByIndex(0);
	return true;
}

void Material::switchTechnique(const string& name)
{
	if (m_pEffect)
	{
		m_pCurrentTechnique=m_pEffect->GetTechniqueByName(name.c_str());
	}
}

//Load the diffuse texture from a specified file and return boolean SM
bool Material::loadDiffuseTexture(const string& filename, IRenderer * pRenderer)
{
	D3D10Renderer *pD3D10Renderer=static_cast<D3D10Renderer*>(pRenderer);
	m_pDiffuseTexture = pD3D10Renderer->loadTexture(filename.c_str());
	if (!m_pDiffuseTexture)
	{
		return false;
	}
	return true;
}
//Load the specular texture from a specified file and return boolean SM
bool Material::loadSpecularTexture(const string& filename, IRenderer * pRenderer)
{
	D3D10Renderer *pD3D10Renderer=static_cast<D3D10Renderer*>(pRenderer);
	m_pSpecularTexture = pD3D10Renderer->loadTexture(filename.c_str());
	if (!m_pSpecularTexture)
	{
		return false;
	}
	return true;
}

//Load cubemap - MD
bool Material::loadCubeTexture(IRenderer * pRenderer)
{
	D3D10Renderer *pD3D10Renderer=static_cast<D3D10Renderer*>(pRenderer);
	m_pCubeTexture = pD3D10Renderer->loadCubeMap();
	if (!m_pCubeTexture)
	{
		return false;
	}
	return true;
}
//Load the bump texture from a specified file and return boolean SM
bool Material::loadBumpTexture(const string& filename, IRenderer * pRenderer)
{
	D3D10Renderer *pD3D10Renderer=static_cast<D3D10Renderer*>(pRenderer);
	m_pBumpTexture = pD3D10Renderer->loadTexture(filename.c_str());
	if (!m_pBumpTexture)
	{
		return false;
	}
	return true;
}

//Load the height texture from a specified file and return boolean SM
bool Material::loadHeightTexture(const string& filename, IRenderer * pRenderer)
{
	D3D10Renderer *pD3D10Renderer=static_cast<D3D10Renderer*>(pRenderer);
	m_pHeightTexture = pD3D10Renderer->loadTexture(filename.c_str());
	if (!m_pHeightTexture)
	{
		return false;
	}
	return true;
}