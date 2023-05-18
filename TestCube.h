#pragma once
#include "Head.h"
#include <windows.h>
#pragma comment(lib,"GLAUX.LIB")
#include "GLAUX.H"
class TestCube
{
public:
	GLuint g_texture = 0;
	float l = 0.5;
	bool flag = 1;
	XMVECTOR Vec_Norm[6];
	XMVECTOR Light_Pos = { 100,50,20 };

	//The Vertex of the Cube
	XMVECTOR CubeVertex[8] =
	{
	{-l,-l,l},
	{l, -l, l},
	{l, l, l},
	{-l, l, l},
	{-l, -l, -l},
	{-l, l, -l},
	{l, l, -l},
	{l,-l,-l},
	};
	//Contect the planes of the cube with the Vertexes
	int plane[6][4] =
	{
		{0,1,2,3},
		{4,5,6,7},
		{7,1,0,4},
		{1,7,6,2},
		{2,6,5,3},
		{3,5,4,0}
	};
	XMVECTOR N_Vec[6] ;
	TestCube(int value);
	void DrawCube(int value);
	void Initlight();
};

