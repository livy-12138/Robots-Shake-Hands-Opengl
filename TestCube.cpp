#include "TestCube.h"

TestCube::TestCube(int value)
{
	l = value;
}

void TestCube::DrawCube(int value)
{
	TestCube Cube(value);
	//求法向量
	float x1, y1, z1, x2, y2, z2,Len;
	for (int i = 0; i < 6; i++)
	{
		x1 = Cube.CubeVertex[Cube.plane[i][1]].m128_f32[0] - Cube.CubeVertex[Cube.plane[i][0]].m128_f32[0];
		y1 = Cube.CubeVertex[Cube.plane[i][1]].m128_f32[1] - Cube.CubeVertex[Cube.plane[i][0]].m128_f32[1];
		z1 = Cube.CubeVertex[Cube.plane[i][1]].m128_f32[2] - Cube.CubeVertex[Cube.plane[i][0]].m128_f32[2];
		x2 = Cube.CubeVertex[Cube.plane[i][2]].m128_f32[0] - Cube.CubeVertex[Cube.plane[i][1]].m128_f32[0];
		y2 = Cube.CubeVertex[Cube.plane[i][2]].m128_f32[1] - Cube.CubeVertex[Cube.plane[i][1]].m128_f32[1];
		z2 = Cube.CubeVertex[Cube.plane[i][2]].m128_f32[2] - Cube.CubeVertex[Cube.plane[i][1]].m128_f32[2];
		Cube.Vec_Norm[i] = { y1 * z2 - y2 * z1,x2 * z1 - x1 * z2,x1 * y2 - x2 * y1 };
		Len = sqrt(Cube.Vec_Norm[i].m128_f32[0] * Cube.Vec_Norm[i].m128_f32[0] + Cube.Vec_Norm[i].m128_f32[1] * Cube.Vec_Norm[i].m128_f32[1] + Cube.Vec_Norm[i].m128_f32[2] * Cube.Vec_Norm[i].m128_f32[2]);
		Cube.Vec_Norm[i].m128_f32[0] *= (1 / Len);
		Cube.Vec_Norm[i].m128_f32[1] *= (1 / Len);
		Cube.Vec_Norm[i].m128_f32[2] *= (1 / Len);
	}
	glPolygonMode(GL_FRONT, GL_FILL);
	glShadeModel(GL_FLAT);
	for (int i = 0; i < 6; i++)
	{
		glNormal3f(Cube.Vec_Norm[i].m128_f32[0], Cube.Vec_Norm[i].m128_f32[1], Cube.Vec_Norm[i].m128_f32[1]);
		//printf("------------------------\n%d:(%f,%f,%f)\n", i, Cube.Vec_Norm[i].m128_f32[0], Cube.Vec_Norm[i].m128_f32[1], Cube.Vec_Norm[i].m128_f32[2]);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); glVertex3fv(Cube.CubeVertex[Cube.plane[i][0]].m128_f32);
		glTexCoord2f(0.0, 1.0); glVertex3fv(Cube.CubeVertex[Cube.plane[i][1]].m128_f32);
		glTexCoord2f(1.0, 1.0); glVertex3fv(Cube.CubeVertex[Cube.plane[i][2]].m128_f32);
		glTexCoord2f(1.0, 0.0); glVertex3fv(Cube.CubeVertex[Cube.plane[i][3]].m128_f32);
		glEnd();
	}
}
void TestCube::Initlight()
{
	GLfloat light0_position[] = { 200,1000,600,1.0 };	//位置光
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	GLfloat light0_ambient[] = { 0.5,0.5,0.5,1.0 };//环境光
	GLfloat light0_diffuse[] = { 0.8,0.8,0.8,1.0 };//漫反射
	GLfloat light0_specular[] = { 1.0,1.0,1.0,1.0 };//高光
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	////添加材质

	GLfloat mat_ambient[] = { 0.5,0.5,0.5,1.0 };
	GLfloat mat_diffuse[] = { 0.8,0.8,0.8,1.0 };
	GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

	//设置高光亮度
	GLfloat mat_shininess[] = { 25.0 };
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}