#include"Head.h"
#include <windows.h>
#pragma comment(lib,"GLAUX.LIB")
#include "GLAUX.H"
GLint winWidth = 1000, winHeight = 600;
GLint Xwmin = -40, Xwmax = 40, Ywmin = -60, Ywmax = 60;
GLint dnear = 1, dfar = 2000;

XMVECTOR Eye = { 0.0f,100.0f,100.0f };
XMVECTOR Up = { 0.0f,1.0f,0.0f };
XMVECTOR ForwardVector = XMVector3Normalize({ 0.0f,0.0f,-1.0f });
XMVECTOR RightVector = XMVector3Normalize(XMVector3Cross(Up, ForwardVector));

bool FullScreen = FALSE;

double oldx = winWidth / 2, oldy = winHeight / 2;
int length = 60;
static int shoulder = 0, elbow = 0, thumb = 0, littlethumb = 0;
static int shoulder0 = 0, elbow0 = 0, thumb0 = 0, littlethumb0 = 0;
bool Picked = false;//¿ØÖÆÇòÊÇ·ñ±»¼ñÆð
float l = 1;

bool view_angle = 1;//1:wander 0:part

bool fog_Flag = 0;

GLuint g_texture[5] = { 0,0,0,0,0 };
GLuint g_sky_texture[6] = { 0,0,0,0,0,0 };

GLint Xoffset = 0, Yoffset = 0, Zoffset = 0;