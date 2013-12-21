#pragma once

#include "VisualComponent.h"

class Skybox:public VisualComponent{
public:
	Skybox();
	~Skybox();
	void loadSkyBox();
	void CreateSphere(int LatLines, int LongLines);
    VisualComponent* SkyBox;

	//====================================================================================From Sample
	//*
	//*
	//*
	HRESULT OnD3D10CreateDevice( ID3D10Device* pd3dDevice, float fSize, WCHAR* strCubeMapFile,
                                 WCHAR* strEffectFileName );
    HRESULT OnD3D10CreateDevice( ID3D10Device* pd3dDevice, float fSize, ID3D10Texture2D* pCubeTexture,
                                 ID3D10ShaderResourceView* pCubeRV, WCHAR* strEffectFileName );

    void    OnD3D10ResizedSwapChain( const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc );
    void    D3D10Render( D3DXMATRIX* pmWorldViewProj );
    void    OnD3D10ReleasingSwapChain();
    void    OnD3D10DestroyDevice();

    ID3D10Texture2D* GetD3D10EnvironmentMap()
    {
        return m_pEnvironmentMap10;
    }
    ID3D10ShaderResourceView* GetD3D10EnvironmentMapRV()
    {
        return m_pEnvironmentRV10;
    }
    void    SetD3D10EnvironmentMap( ID3D10Texture2D* pCubeTexture )
    {
        m_pEnvironmentMap10 = pCubeTexture;
    }
	//*
	//*
	//*
	//=============================================================================================

private:
	//==================================================================================From sample
	//*
	//*
	 ID3D10Texture2D* m_pEnvironmentMap10;
    ID3D10ShaderResourceView* m_pEnvironmentRV10;
    ID3D10Effect* m_pEffect10;
    ID3D10Buffer* m_pVB10;
    ID3D10InputLayout* m_pVertexLayout10;
    ID3D10Device* m_pd3dDevice10;
    ID3D10EffectTechnique* m_pTechSkyBox;
    ID3D10EffectMatrixVariable* m_pmInvWorldViewProjection;
    ID3D10EffectShaderResourceVariable* g_pEnvironmentTexture;
    float m_fSize;
	 ID3D10Texture2D* pCubeTexture;
//   ID3D10ShaderResourceView* pCubeRV = NULL;
	//*
	//*
	//=============================================================================================
};