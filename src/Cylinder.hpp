#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415927

class Cylinder{
public:
	GLfloat radius;
	GLfloat height;
	GLubyte R;
	GLubyte G;
	GLubyte B;
	GLfloat x;
	GLfloat y;
	GLfloat angle;
	GLfloat angle_stepsize;

	Cylinder();
	void draw();

};
