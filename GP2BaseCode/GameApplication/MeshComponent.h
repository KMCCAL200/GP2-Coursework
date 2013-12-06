#include "VisualComponent.h"

class MeshComponent:public VisualComponent
{
public:
	MeshComponent(){};
	~MeshComponent(){};

	bool create(IRenderer * pRenderer);
};