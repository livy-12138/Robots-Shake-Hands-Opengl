#pragma once
#include "Head.h"
class Coordinate_Axis
{
public:
	int length;
	XMVECTOR X_Color = { 1.0f, 0.0f, 0.0f };
	XMVECTOR Y_Color = { 0.0f, 1.0f, 0.0f };
	XMVECTOR Z_Color = { 0.0f, 0.0f, 1.0f };
	Coordinate_Axis(int value);
	Coordinate_Axis();
	void Draw_Coordinate_Axis(int value);
};

