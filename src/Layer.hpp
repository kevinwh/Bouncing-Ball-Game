#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>


#define PI 3.1415927

class Layer{
public:
	GLfloat radius;
	GLfloat height;
	GLfloat S;
	GLfloat x;
	GLfloat y;
	GLfloat angle;
	GLfloat angle_stepsize;

	Layer();
	void draw(GLfloat DEGREE, GLfloat anBegin, GLfloat anEnd, GLint R, GLint G,
			GLint B, GLfloat H);
	void layer_rotate();

};
