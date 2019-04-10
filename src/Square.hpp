#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415927

class Square {
public:
	GLfloat x1;
	GLfloat x2;
	GLfloat y1;
	GLfloat y2;
    Square();
    void draw();
};
