#include "main.h"
#include "Camera.h"
#include "Coordinate_Axis.h"
#include "TestCube.h"
static GLfloat sx = 0, sy = 0, sz = 0;
Camera Cam(Eye,ForwardVector,Up);
Coordinate_Axis Axis;
TestCube TCube(1);

GLvoid DrawSky(float scale)
{
	glPushMatrix();
	glTranslatef(0.0, scale - 1, 0.0);
	glScalef(scale, scale, scale);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_sky_texture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 前
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_sky_texture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);// 左
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_sky_texture[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 右
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_sky_texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 后
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_sky_texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 上
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_sky_texture[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 下
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	glPopMatrix();
}

void idle(void)
{
	if (!Picked)
	{
		if (shoulder > -5)
			shoulder--;
		else if (elbow > -45)
			elbow--;
	}
	if (shoulder == -5 && elbow == -45)
		Picked = true;
	if (Picked)
	{
		if (shoulder < 0)
			shoulder++;
		else if (elbow < 0)
			elbow++;
	}

	if (shoulder == 0 && elbow == 0)
	{
		Picked = false;
		thumb = 0;
		littlethumb = 0;
	}

	Sleep(100);
	glutPostRedisplay();
}

void Robot_hand(int shake)//1:moveing hand 0:another one
{
	glPushMatrix();
	glTranslatef(-1.2, 1.6, 0.0);
	if(shake)
		glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	else
		glRotatef((GLfloat)shoulder0, 0.0, 0.0, 1.0);
	glTranslatef(0.6, -0.8, 0.0);

	glPushMatrix();
	glScalef(2.0, 1.0, 0.4);
	TCube.DrawCube(1);
	glPopMatrix();

	glTranslatef(1.0, 0.0, 0.0);
	if (shake)
	{
		glRotatef(40, 1, 1, 0);
		glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	}
	else
		glRotatef((GLfloat)elbow0, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);

	glPushMatrix();
	glScalef(2.0, 1.0, 0.4);
	TCube.DrawCube(1);
	glPopMatrix();

	{
		glPushMatrix();

		glTranslatef(0.0, 0.5, 0.2);
		glTranslatef(1.0, 0.0, 0.0);
		glRotatef((GLfloat)thumb, 1.0, 0.0, .0);
		glTranslatef(0.3, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.6, 0.2, 0.1);
		TCube.DrawCube(1);
		glPopMatrix();

		glTranslatef(0.3, 0.0, 0.0);
		glRotatef((GLfloat)littlethumb, 0.0, 0.0, 1.0);
		glTranslatef(0.2, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.4, 0.2, 0.1);
		TCube.DrawCube(1);
		glPopMatrix();

		glPopMatrix();
	}

	{
		glPushMatrix();

		glTranslatef(0.0, -0.5, 0.2);
		glTranslatef(1.0, 0.0, 0.0);
		glRotatef((GLfloat)thumb, 1.0, 0.0, 0.0);
		glTranslatef(0.3, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.6, 0.2, 0.1);
		TCube.DrawCube(1);
		glPopMatrix();

		glTranslatef(0.3, 0.0, 0.0);
		glRotatef((GLfloat)littlethumb, 0.0, 0.0, 1.0);
		glTranslatef(0.2, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.4, 0.2, 0.1);
		TCube.DrawCube(1);
		glPopMatrix();

		glPopMatrix();
	}

	{
		glPushMatrix();

		glTranslatef(0.0, 0.2, 0.2);
		glTranslatef(1.0, 0.0, 0.0);
		glRotatef((GLfloat)thumb, 1.0, 0.0, 0.0);
		glTranslatef(0.3, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.6, 0.2, 0.1);
		TCube.DrawCube(1);
		glPopMatrix();

		glTranslatef(0.3, 0.0, 0.0);
		glRotatef((GLfloat)littlethumb, 0.0, 0.0, 1.0);
		glTranslatef(0.2, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.4, 0.2, 0.1);
		TCube.DrawCube(1);
		glPopMatrix();

		glPopMatrix();
	}

	{
		glPushMatrix();

		glTranslatef(0.0, -0.2, 0.2);
		glTranslatef(1.0, 0.0, 0.0);
		glRotatef((GLfloat)thumb, 1.0, 0.0, 0.0);
		glTranslatef(0.3, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.6, 0.2, 0.1);
		TCube.DrawCube(1);
		glPopMatrix();

		glTranslatef(0.3, 0.0, 0.0);
		glRotatef((GLfloat)littlethumb, 0.0, 0.0, 1.0);
		glTranslatef(0.2, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.4, 0.2, 0.1);
		TCube.DrawCube(1);
		glPopMatrix();

		glPopMatrix();
	}

	{
		glPushMatrix();

		if (shake)
			glTranslatef(0.0, -0.4, -0.2);
		else
			glTranslatef(0.0, 0.4, -0.2);
		glTranslatef(1.0, 0.0, 0.0);
		glRotatef((GLfloat)thumb, -1.0, 0.0, 0.0);
		glTranslatef(0.3, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.6, 0.2, 0.1);
		TCube.DrawCube(1);
		glPopMatrix();

		glTranslatef(0.3, 0.0, 0.0);
		glRotatef((GLfloat)littlethumb, 0.0, 0.0, 1.0);
		glTranslatef(0.2, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.4, 0.2, 0.1);
		TCube.DrawCube(1);
		glPopMatrix();

		glPopMatrix();
	}


	glPopMatrix();
}

void LoadGLTextures(GLuint& unTexture,const char* Path)
{
	AUX_RGBImageRec* TextureImage;
	TextureImage = auxDIBImageLoad(Path);
	glGenTextures(1, &unTexture);
	glBindTexture(GL_TEXTURE_2D, unTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
void OnDisplay(void)
{
	GLfloat mat_ambient2[] = { 0.7,0.7,0.7,1 };
	GLfloat mat_diffuse2[] = { 0.7,0.7,0.7,1};
	GLfloat mat_specular2[] = { 0.7,0.7,0.7,1 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	for (int i = 0; i < 5; i++)
	{
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, g_texture[4]);
		glTranslatef(i*100-200, 100, -100);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glScalef(100, 100, 2);
		TCube.DrawCube(1);
		glPopMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_BLEND);
	}
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//---------------light 0
	GLfloat light0_position[] = { 0,500,0,1.0 };	//位置光
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	GLfloat light0_ambient[] = { 0.8,0.8,0.8,1.0 };//环境光
	GLfloat light0_diffuse[] = { 0.8,0.8,0.8,1.0 };//漫反射
	GLfloat light0_specular[] = { 0.8,0.8,0.8,1.0 };//高光
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	//-----------------------
 	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//设置高光亮度
	GLfloat mat_shininess[] = { 25.0 };
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void robot(void)
{
	//---------------Robot1
//leg1
	glBindTexture(GL_TEXTURE_2D, g_texture[3]);
	glPushMatrix();
	glTranslated(0, 25, 15);
	glScaled(20, 50, 15);
	TCube.DrawCube(1);
	glPopMatrix();
	//leg2
	glPushMatrix();
	glTranslated(0, 25, -15);
	glScaled(20, 50, 15);
	TCube.DrawCube(1);
	glPopMatrix();
	//body
	glBindTexture(GL_TEXTURE_2D, g_texture[1]);
	glPushMatrix();
	glTranslated(0, 75, 0);
	glScaled(30, 50, 50);
	TCube.DrawCube(1);
	glPopMatrix();
	//hand1
	glEnable(GL_COLOR_MATERIAL);
	GLfloat mat_ambient2[] = { 0.7,0.0,0.0,1.0 };
	GLfloat mat_diffuse2[] = { 0.7,0.0,0.0,1.0 };
	GLfloat mat_specular2[] = { 0.7,0.0,0.0,1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glBindTexture(GL_TEXTURE_2D, g_texture[0]);
	glPushMatrix();
	glTranslatef(-20, 85, 28);
	glScaled(15, 15, 15);
	glRotatef(-130, 0, 0, 1);
	Robot_hand(1);
	glPopMatrix();
	glDisable(GL_COLOR_MATERIAL);
	//hand2
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	GLfloat mat_ambient3[] = { 0.0,0.0,0.7,1.0 };
	GLfloat mat_diffuse3[] = { 0.0,0.0,0.7,1.0 };
	GLfloat mat_specular3[] = { 0.0,0.0,0.7,1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse3);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular3);
	glPushMatrix();
	glTranslatef(15, 75, -28);
	glScaled(15, 15, 15);
	glRotatef(-90, 0, 0, 1);
	glRotatef(-180, 1, 0, 0);
	Robot_hand(0);
	glPopMatrix();
	glDisable(GL_COLOR_MATERIAL);
	//head
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(0, 110, 0);
	auxSolidSphere(15);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
}

void displayScene(void)
{
//------------------set camera
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	if(!view_angle)
	{
		Eye = { 0,60 - (GLfloat)elbow,0 };
		Up = { 0.0f,1.0f,0.0f };
		ForwardVector = XMVector3Normalize({ -1.0f,-0.7f,0.0f });
		RightVector = XMVector3Normalize(XMVector3Cross(Up, ForwardVector));
	}
	Cam.Update_Camera(Eye, ForwardVector, Up);
	glMatrixMode(GL_MODELVIEW);
//----------------Coordinates
   	//Axis.Draw_Coordinate_Axis(2000);
	//------------------地面
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_texture[2]);
	GLfloat mat_ambient1[] = { 0.7,0.7,0.7,1.0 };
	GLfloat mat_diffuse1[] = { 0.7,0.7,0.7,1.0 };
	GLfloat mat_specular1[] = { 0.7,0.7,0.7,1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			glPushMatrix();
			glColor4f(0.9,0.9,0.9, 0.0);
			glTranslated(-500+250*i, 0, -500+250*j);
			glScaled(50, 50, 50);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0); glVertex3d(5, 0, 0);
			glTexCoord2f(1.0, 0.0); glVertex3d(5, 0, 5);
			glTexCoord2f(1.0, 1.0); glVertex3d(0, 0, 5);
			glTexCoord2f(0.0, 1.0); glVertex3d(0, 0, 0);
			glEnd();
			glPopMatrix();
		}
	}
	glPushMatrix();
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(40,0,-8);
	robot();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-40, 0, 8);
	glRotatef(180, 0, 1, 0);
	robot();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	OnDisplay();
	//-----------------skybox
	DrawSky(500);
	glutSwapBuffers();
}
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,1.0f*winWidth/winHeight, dnear, dfar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Cam.Update_Camera(Eye, ForwardVector, Up);
}
void ChangeAngle()
{
	if (view_angle)
	{
		Eye = { 0.0f,100.0f,100.0f };
		Up = { 0.0f,1.0f,0.0f };
		ForwardVector = XMVector3Normalize({ 0.0f,0.0f,-1.0f });
		RightVector = XMVector3Normalize(XMVector3Cross(Up, ForwardVector));
	}
	else
	{
		Eye = { 0,60- (GLfloat)elbow,0 };
		Up = { 0.0f,1.0f,0.0f };
		ForwardVector = XMVector3Normalize({ -1.0f,-0.7f,0.0f});
		RightVector = XMVector3Normalize(XMVector3Cross(Up, ForwardVector));
	}
}
void Move(int Xoffset, int Yoffset,int Zoffset)
{
	if (view_angle)
	{
		Eye += 10 * RightVector * Xoffset;
		Eye.m128_f32[0] += ForwardVector.m128_f32[0] * 5 * Yoffset;
		Eye.m128_f32[2] += ForwardVector.m128_f32[2] * 5 * Yoffset;
		Eye.m128_f32[1] += 5 * Zoffset;
		glutPostRedisplay();
	}
}

void KeyBoardInput(GLubyte curvePlotKey, GLint xMouse, GLint yMouse)
{
	GLint Xoffset = 0, Yoffset = 0, Zoffset = 0;
	switch (curvePlotKey)
	{
	case'w':
		Yoffset = 1;;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case'a':
		Xoffset = 1;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case's':
		Yoffset = -1;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case'd':
		Xoffset = -1;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case'q':
		Zoffset = -1;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case'e':
		Zoffset = 1;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case'1':
		view_angle = 1;
		ChangeAngle();
		break;
	case'2':
		view_angle = 0;
		ChangeAngle();
		break;
	case'f':
		if (!fog_Flag)
			fog_Flag = 1;
		else
			fog_Flag = 0;
		break;
	default:
		break;
	}
}
void RotateCamera(double x, double y)
{
	if (view_angle)
	{
		ForwardVector = XMVector3Normalize(7 * y * Up + ForwardVector);
		//Up = XMVector3Normalize(XMVector3Cross(ForwardVector, RightVector));
		ForwardVector = XMVector3Normalize(7 * x * RightVector + ForwardVector);
		RightVector = XMVector3Normalize(XMVector3Cross(Up, ForwardVector));
	}
}
void MouseInput( GLint xMouse, GLint yMouse)
{	
	RotateCamera(-(oldx-xMouse)/winWidth,-(oldy - yMouse)/winHeight);
	oldx = xMouse;
	oldy = yMouse;
}
void SpecialKey(int key, int x, int y)
{
	GLint Xoffset = 0, Yoffset = 0, Zoffset = 0;
	switch (key) {
	case GLUT_KEY_PAGE_DOWN:
		Zoffset = -1;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case GLUT_KEY_PAGE_UP:
		Zoffset = 1;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case GLUT_KEY_UP:
		Yoffset = 1;;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case GLUT_KEY_DOWN:
		Yoffset = -1;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case GLUT_KEY_RIGHT:
		Xoffset = -1;
		Move(Xoffset, Yoffset, Zoffset);
		break;
	case GLUT_KEY_LEFT:
		Xoffset = 1;
		Move(Xoffset, Yoffset, Zoffset);
		break;
		glutPostRedisplay();
	default:
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Solid-Frame Quadric Surfaces");
	init();
	glEnable(GL_TEXTURE_2D);
	LoadGLTextures(g_texture[0], "hands.bmp");
	LoadGLTextures(g_texture[1], "body.bmp");
	LoadGLTextures(g_texture[2], "floor.bmp");
	LoadGLTextures(g_texture[3], "legs.bmp");
	LoadGLTextures(g_texture[4], "rope.bmp");
	LoadGLTextures(g_sky_texture[0], "sky1.bmp");
	LoadGLTextures(g_sky_texture[1], "sky4.bmp");
	LoadGLTextures(g_sky_texture[2], "sky2.bmp");
	LoadGLTextures(g_sky_texture[3], "sky3.bmp");
	LoadGLTextures(g_sky_texture[4], "sky5.bmp");
	LoadGLTextures(g_sky_texture[5], "sky5.bmp");
	glutSetCursor(GLUT_CURSOR_NONE);
	glutDisplayFunc(displayScene);
	glutReshapeFunc(winReshapeFcn);
	glutKeyboardFunc(KeyBoardInput);
	glutSpecialFunc(SpecialKey);
	glutPassiveMotionFunc(MouseInput);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
