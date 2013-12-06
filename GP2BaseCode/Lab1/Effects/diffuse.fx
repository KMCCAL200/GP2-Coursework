float4x4 matWorld:WORLD<string UIWidget="None";>;    //mat:matrix
float4x4 matView:VIEW<string UIWidget="None";>; 
float4x4 matProjection:PROJECTION<string UIWidget="None";>; 

float3 lightDirection:DIRECTION
<
string UIWidget="None";
string Object = "DirectionalLight";
>;

float4 diffuseMaterial
<
string UIName="Diffuse Material";
string UIWidget="Color";
>;

float4 diffuseLightColour:COLOR
<
string UIWidget="None";
string Object = "DirectionalLight";
>;


float4 ambientMaterial
<
string UIName="Ambient Material";
string UIWidget="Color";
>;

float4 ambientLightColour<
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
};

//Vector Shader
PS_INPUT VS(VS_INPUT input)
{
	PS_INPUT output = (PS_INPUT)0;
	
	float4x4 matViewProjection = mul(matView, matProjection); //multiply
	float4x4 matWorldViewProjection = mul(matWorld, matViewProjection);
	
	output.normal= mul(input.normal, matWorld);
	output.pos = mul(input.pos, matWorldViewProjection);
	return output;
	}
	
//Pixel Shader
float4 PS(PS_INPUT input):SV_TARGET
{
	float3 normal = normalize(input.normal);
	float3 lightDir = normalize(lightDirection);
	
	float diffuseHighlight=saturate(dot(normal,lightDir));
	
return (ambientMaterial*ambientLightColour)+(diffuseMaterial*diffuseLightColour*diffuseHighlight);
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
