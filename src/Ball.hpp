#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415927

class Ball {
public:
	GLint flag;
	GLint sound;
	GLfloat tx;
	GLfloat ty;
	GLfloat tz;
	GLfloat ball_x;
	GLfloat ball_y;
	GLfloat ball_z;
	GLfloat speed;
	GLfloat top;
	GLfloat base;

	Ball();
	void drawBall();

};
