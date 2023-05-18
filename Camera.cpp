#include "Camera.h"

Camera::Camera(XMVECTOR Eye, XMVECTOR ForwardVector, XMVECTOR Up)
{
	eye = Eye;
	center = ForwardVector+Eye;
	up = Up;
}
void Camera::Update_Camera(XMVECTOR EYE, XMVECTOR ForwardVector, XMVECTOR UP)
{
	eye = EYE;
	center = ForwardVector+EYE;
	up = UP;
	//------------------set camera
	gluLookAt(eye.m128_f32[0], eye.m128_f32[1], eye.m128_f32[2],center.m128_f32[0], center.m128_f32[1], center.m128_f32[2],UP.m128_f32[0], UP.m128_f32[1], UP.m128_f32[2]);
}
