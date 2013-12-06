float4x4 matWorld:WORLD<string UIWidget="None";>;    
float4x4 matView:VIEW<string UIWidget="None";>; 
float4x4 matProjection:PROJECTION<string UIWidget="None";>; 

float4 specularMaterial<
string UIName="Specular Material";
string UIWidget="Color";
> = {1.0f,1.0f,1.0f,1.0f};

float4 specularLightColour<
string UIName="Specular Light Colour";
string UIWidget="Color";
> = {1.0f,1.0f,1.0f,1.0f};

float4 cameraPosition:POSITION<
string UIName="Camera Position";
string Object = "Perspective";
> ;

float3 lightDirection:DIRECTION
<
string UIWidget="None";
string Object = "DirectionalLight";
>;

float4 diffuseMaterial
<
string UIName="Diffuse Material";
string UIWidget="Color";
> = {0.8f,0.8f,0.8f,1.0f};

float4 diffuseLightColour:COLOR
<
string UIWidget="None";
string Object = "DirectionalLight";
> = {1.0f,1.0f,1.0f,1.0f};


float4 ambientMaterial
<
string UIName="Ambient Material";
string UIWidget="Color";
>;

float4 ambientLightColour:AMBIENT<
string UIName="Ambient Light Colour";
string UIWidget="Color";
>;

float4 objectColour
<
	string UIName="ObjectColour";
	string UIWidget="Color";
> = {1,1,1,1};

//Vector Shader Input
struct VS_INPUT
{
	float4 pos:POSITION;
	float3 normal:NORMAL;
	
};

//Pixel Shader Input
struct PS_INPUT
{
	float4  pos:SV_POSITION;
	float3 normal:NORMAL;
	
	//NEW==================
	float4 cameraDirection:VIEWDIR;
	//=====================
	};

//Vector Shader
PS_INPUT VS(VS_INPUT input)
{
	PS_INPUT output = (PS_INPUT)0;
	
	float4x4 matViewProjection = mul(matView, matProjection); //multiply
	float4x4 matWorldViewProjection = mul(matWorld, matViewProjection);
	
	output.normal= mul(input.normal, matWorld);
	output.pos = mul(input.pos, matWorldViewProjection);
	
	//NEW==================
	float4 worldPos=mul(input.pos, matWorld);
	output.cameraDirection = normalize(cameraPosition-worldPos);
	//=====================
	
	return output;
	}
	
//Pixel Shader
float4 PS(PS_INPUT input):SV_TARGET
{
	float3 normal = normalize(input.normal);
	float3 lightDir = normalize(lightDirection);
	
	float diffuseHighlight=saturate(dot(normal,lightDir));
	
	//NEW================
	float3 halfVec = normalize(lightDirection + input.cameraDirection);
	float specular = pow(saturate(dot(normal, halfVec)),2);
	//===================
	
return (ambientMaterial*ambientLightColour)+(diffuseMaterial*diffuseLightColour*diffuseHighlight)
+(specularMaterial*specularLightColour*specular);
}

RasterizerState DisableCulling
{
	CullMode = NONE;	
};

technique10 Render
{
	pass P0
	{
		SetVertexShader(CompileShader(vs_4_0, VS()));
		SetGeometryShader(NULL);
		SetPixelShader(CompileShader(ps_4_0, PS()));
		SetRasterizerState(DisableCulling);
	}
}
