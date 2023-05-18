#include "Coordinate_Axis.h"
 Coordinate_Axis::Coordinate_Axis(int value)
{
	length = value;
}
 Coordinate_Axis::Coordinate_Axis()
 {
	 length = 30;
 }
void Coordinate_Axis::Draw_Coordinate_Axis(int value)
{
	glDisable(GL_LIGHTING);
	Coordinate_Axis World_Coordinate_Axis(value);
	glLineWidth(4.0);
	//-------------------------x axis
	glColor3fv(X_Color.m128_f32);
	glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(value, 0, 0);
	glEnd();
	//------------------------y axis
	glColor3fv(Y_Color.m128_f32);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, value, 0);
	glEnd();
	//------------------------z axis
	glColor3fv(Z_Color.m128_f32);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, value);
	glEnd();
	glFlush();
	glEnable(GL_LIGHTING);
}