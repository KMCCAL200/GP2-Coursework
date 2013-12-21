#include "Skybox.h"
#include "../D3D10Renderer/D3D10Renderer.h"

//void Skybox::loadSkyBox(){
//
//
//};
// D3D10


struct SKYBOX_VERTEX
{
    D3DXVECTOR4 pos;
};



const D3D10_INPUT_ELEMENT_DESC g_aVertexLayout[] =
{
    { "POSITION",  0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0,  D3D10_INPUT_PER_VERTEX_DATA, 0 },
};


//-----------------------------------------------------------------------------
// Name: CSkybox
// Desc: Constructor
//-----------------------------------------------------------------------------
Skybox::Skybox()
{
    
    m_pEnvironmentMap10 = NULL;
    m_pEffect10 = NULL;
    m_pVB10 = NULL;
    m_pVertexLayout10 = NULL;
    m_pd3dDevice10 = NULL;
    m_pTechSkyBox = NULL;
    m_pmInvWorldViewProjection = NULL;
    g_pEnvironmentTexture = NULL;

    m_fSize = 1.0f;
}

void loadCubeTexture(IRenderer * pRenderer){
	
	 ID3D10Resource* pRes = NULL;
    ID3D10Texture2D* pCubeTexture = NULL;
	
	D3D10Renderer *pD3D10Renderer=static_cast<D3D10Renderer*>(pRenderer);
	
	D3DX10_IMAGE_LOAD_INFO LoadInfo;
    LoadInfo.MiscFlags = D3D10_RESOURCE_MISC_TEXTURECUBE;

	
	
	//D3DX10CreateTextureFromFile( pRenderer, strPath, &LoadInfo, NULL, &pRes, NULL )
}
//-----------------------------------------------------------------------------
HRESULT Skybox::OnD3D10CreateDevice( ID3D10Device* pd3dDevice, float fSize, WCHAR* strCubeMapFile,
                                      WCHAR* strEffectFileName )
{
    HRESULT hr;

    WCHAR strPath[MAX_PATH];
    //V_RETURN( DXUTFindDXSDKMediaFileCch( strPath, MAX_PATH, strCubeMapFile ) );

    ID3D10Resource* pRes = NULL;
    ID3D10Texture2D* pCubeTexture = NULL;
    ID3D10ShaderResourceView* pCubeRV = NULL;

    D3DX10_IMAGE_LOAD_INFO LoadInfo;
    LoadInfo.MiscFlags = D3D10_RESOURCE_MISC_TEXTURECUBE;

    //V_RETURN( )
	D3DX10CreateTextureFromFile( pd3dDevice, strPath, &LoadInfo, NULL, &pRes, NULL );
    if( pRes )
    {
        D3D10_TEXTURE2D_DESC desc;
        ZeroMemory( &desc, sizeof( D3D10_TEXTURE2D_DESC ) );
        pRes->QueryInterface( __uuidof( ID3D10Texture2D ), ( LPVOID* )&pCubeTexture );
        pCubeTexture->GetDesc( &desc );
        //SAFE_RELEASE( pRes );

        D3D10_SHADER_RESOURCE_VIEW_DESC SRVDesc;
        ZeroMemory( &SRVDesc, sizeof( SRVDesc ) );
        SRVDesc.Format = desc.Format;
        SRVDesc.ViewDimension = D3D10_SRV_DIMENSION_TEXTURECUBE;
        SRVDesc.TextureCube.MipLevels = desc.MipLevels;
        SRVDesc.TextureCube.MostDetailedMip = 0;
       // V_RETURN( )
		pd3dDevice->CreateShaderResourceView( pCubeTexture, &SRVDesc, &pCubeRV );
    }

    return OnD3D10CreateDevice( pd3dDevice, fSize, pCubeTexture, pCubeRV, strEffectFileName );
}


//-----------------------------------------------------------------------------
HRESULT Skybox::OnD3D10CreateDevice( ID3D10Device* pd3dDevice, float fSize, ID3D10Texture2D* pCubeTexture,
                                      ID3D10ShaderResourceView* pCubeRV, WCHAR* strEffectFileName )
{
    HRESULT hr;

    m_pd3dDevice10 = pd3dDevice;
    m_fSize = fSize;
    m_pEnvironmentMap10 = pCubeTexture;
    m_pEnvironmentRV10 = pCubeRV;

    // Read the D3DX effect file
    WCHAR str[MAX_PATH];
   // V_RETURN( DXUTFindDXSDKMediaFileCch( str, MAX_PATH, strEffectFileName ) );

    // If this fails, there should be debug output as to 
    // they the .fx file failed to compile
    DWORD dwShaderFlags = D3D10_SHADER_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    // Set the D3D10_SHADER_DEBUG flag to embed debug information in the shaders.
    // Setting this flag improves the shader debugging experience, but still allows 
    // the shaders to be optimized and to run exactly the way they will run in 
    // the release configuration of this program.
    dwShaderFlags |= D3D10_SHADER_DEBUG;
#endif

    // Check for D3D10 linear filtering on DXGI_FORMAT_R32G32B32A32.  If the card can't do it, use point filtering.  Pointer filter may cause
    // banding in the lighting.
    UINT FormatSupport = 0;
    //V_RETURN() 
	pd3dDevice->CheckFormatSupport( DXGI_FORMAT_R32G32B32A32_FLOAT, &FormatSupport ) ;

    char strUsePointCubeSampling[MAX_PATH];
    sprintf_s( strUsePointCubeSampling, ARRAYSIZE( strUsePointCubeSampling ), "%d", ( FormatSupport & D3D10_FORMAT_SUPPORT_SHADER_SAMPLE ) > 0 );

    D3D10_SHADER_MACRO macros[] =
    {
        { "USE_POINT_CUBE_SAMPLING", strUsePointCubeSampling },
        { NULL, NULL }
    };

   // V_RETURN( )
	D3DX10CreateEffectFromFile( str, macros, NULL, "fx_4_0", dwShaderFlags, 0, pd3dDevice, NULL,
                                              NULL, &m_pEffect10, NULL, NULL );

    // Get the technique
    m_pTechSkyBox = m_pEffect10->GetTechniqueByName( "Skybox" );

    // Get the variables
    m_pmInvWorldViewProjection = m_pEffect10->GetVariableByName( "g_mInvWorldViewProjection" )->AsMatrix();
    g_pEnvironmentTexture = m_pEffect10->GetVariableByName( "g_EnvironmentTexture" )->AsShaderResource();

    // Create an input layout that matches the technique
    D3D10_PASS_DESC PassDesc;
    //V_RETURN() 
	m_pTechSkyBox->GetPassByIndex( 0 )->GetDesc( &PassDesc ) ;
    //V_RETURN() 
	pd3dDevice->CreateInputLayout( g_aVertexLayout, 1, PassDesc.pIAInputSignature,
                                             PassDesc.IAInputSignatureSize, &m_pVertexLayout10 ) ;


    return S_OK;
}


//-----------------------------------------------------------------------------
void Skybox::OnD3D10ResizedSwapChain( const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc )
{
    HRESULT hr;

    if( m_pd3dDevice10 == NULL )
        return;

    // Fill the vertex buffer
    SKYBOX_VERTEX* pVertex = new SKYBOX_VERTEX[ 4 ];
    if( !pVertex )
        return;

    // Map texels to pixels 
    float fHighW = -1.0f - ( 1.0f / ( float )pBackBufferSurfaceDesc->Width );
    float fHighH = -1.0f - ( 1.0f / ( float )pBackBufferSurfaceDesc->Height );
    float fLowW = 1.0f + ( 1.0f / ( float )pBackBufferSurfaceDesc->Width );
    float fLowH = 1.0f + ( 1.0f / ( float )pBackBufferSurfaceDesc->Height );

    /*pVertex[0].pos = D3DXVECTOR4(fHighW, fLowH, 0.5f, 1.0f);
       pVertex[1].pos = D3DXVECTOR4(fLowW, fLowH, 0.5f, 1.0f);
       pVertex[2].pos = D3DXVECTOR4(fHighW, fHighH, 0.5f, 1.0f);
       pVertex[3].pos = D3DXVECTOR4(fLowW, fHighH, 0.5f, 1.0f);*/
    pVertex[0].pos = D3DXVECTOR4( fLowW, fLowH, 1.0f, 1.0f );
    pVertex[1].pos = D3DXVECTOR4( fLowW, fHighH, 1.0f, 1.0f );
    pVertex[2].pos = D3DXVECTOR4( fHighW, fLowH, 1.0f, 1.0f );
    pVertex[3].pos = D3DXVECTOR4( fHighW, fHighH, 1.0f, 1.0f );

    UINT uiVertBufSize = 4 * sizeof( SKYBOX_VERTEX );
    D3D10_BUFFER_DESC vbdesc =
    {
        uiVertBufSize,
        D3D10_USAGE_IMMUTABLE,
        D3D10_BIND_VERTEX_BUFFER,
        0,
        0
    };

    D3D10_SUBRESOURCE_DATA InitData;
    InitData.pSysMem = pVertex;
    InitData.SysMemPitch = 0;
    InitData.SysMemSlicePitch = 0;
    //V() 
	m_pd3dDevice10->CreateBuffer( &vbdesc, &InitData, &m_pVB10 ) ;
    //SAFE_DELETE_ARRAY( pVertex );
}


//-----------------------------------------------------------------------------
// Name: Render
// Desc: 
//-----------------------------------------------------------------------------
void Skybox::D3D10Render( D3DXMATRIX* pmWorldViewProj )
{
    m_pd3dDevice10->IASetInputLayout( m_pVertexLayout10 );

    D3DXMATRIX mInvWorldViewProj;
    D3DXMatrixInverse( &mInvWorldViewProj, NULL, pmWorldViewProj );
    m_pmInvWorldViewProjection->SetMatrix( ( float* )&mInvWorldViewProj );

    g_pEnvironmentTexture->SetResource( m_pEnvironmentRV10 );

    UINT uStrides = sizeof( SKYBOX_VERTEX );
    UINT uOffsets = 0;
    ID3D10Buffer* pBuffers[1] = { m_pVB10 };
    m_pd3dDevice10->IASetVertexBuffers( 0, 1, pBuffers, &uStrides, &uOffsets );
    m_pd3dDevice10->IASetIndexBuffer( NULL, DXGI_FORMAT_R32_UINT, 0 );
    m_pd3dDevice10->IASetPrimitiveTopology( D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP );

    // Draw
    D3D10_TECHNIQUE_DESC techDesc;

    ID3D10EffectTechnique* pTech = m_pTechSkyBox;

    pTech->GetDesc( &techDesc );
    for( UINT p = 0; p < techDesc.Passes; ++p )
    {
        pTech->GetPassByIndex( p )->Apply( 0 );
        m_pd3dDevice10->Draw( 4, 0 );
    }
}


//-----------------------------------------------------------------------------
void Skybox::OnD3D10ReleasingSwapChain()
{
    //SAFE_RELEASE( m_pVB10 );
}


//-----------------------------------------------------------------------------
void Skybox::OnD3D10DestroyDevice()
{
    m_pd3dDevice10 = NULL;
    /*SAFE_RELEASE( m_pEnvironmentMap10 );
    SAFE_RELEASE( m_pEnvironmentRV10 );
    SAFE_RELEASE( m_pEffect10 );
    SAFE_RELEASE( m_pVertexLayout10 );*/
}