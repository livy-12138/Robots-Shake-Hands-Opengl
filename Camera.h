#pragma once
#include "Head.h"
class Camera
{
public:
	
	XMVECTOR eye;
	XMVECTOR center;	
	XMVECTOR up;

	Camera(XMVECTOR Eye, XMVECTOR ForwardVector, XMVECTOR Up);

	void Update_Camera(XMVECTOR EYE, XMVECTOR ForwardVector, XMVECTOR UP);
};

