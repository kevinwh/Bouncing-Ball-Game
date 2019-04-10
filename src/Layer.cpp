#include "Layer.hpp"

//extern Camera myCamera;
//extern Light myLight;

Layer::Layer() {
	radius = 0.4;
	height = 0.1;
	S = 1.5;
	x = 0.0;
	y = 0.0;
	angle = 0.0;
	angle_stepsize = 0.001;
}

void Layer::draw(GLfloat DEGREE, GLfloat anBegin, GLfloat anEnd, GLint R, GLint G, GLint B, GLfloat H) {
	DEGREE = DEGREE /360 *2*PI;
	anBegin = anBegin /360 *2*PI ;
	anEnd = anEnd /360 *2*PI + DEGREE;
	GLfloat x1 = 0.0, x2 = 0.0;
	GLfloat y1 = 0.0, y2 = 0.0;

	/** Draw the tube */
	glColor3ub(R - 40, G - 40, B - 40);
	glBegin(GL_LINES);
	angle = anBegin + DEGREE;
	x1 = radius * cos(angle) * S;
	y1 = radius * sin(angle) * S;
	while (angle < anEnd) {
		x = radius * cos(angle) * S;
		y = radius * sin(angle) * S;
		glVertex3f(x, y, height + H);
		glVertex3f(x, y, 0.0 + H);
		angle += angle_stepsize;
	}
	x2 = radius * cos(angle) * S;
	y2 = radius * sin(angle) * S;
	glEnd();

	glColor3ub(R - 50, G - 50, B - 50);
	glBegin(GL_POLYGON);
	glVertex3f(x1 / 2, y1 / 2, 0 + H);
	glVertex3f(x1 / 2, y1 / 2, height + H);
	glVertex3f(x1, y1, height + H);
	glVertex3f(x1, y1, 0 + H);
	glEnd();

	glColor3ub(R - 50, G - 50, B - 50);
	glBegin(GL_POLYGON);
	glVertex3f(x2, y2, 0 + H);
	glVertex3f(x2, y2, height + H);
	glVertex3f(x2 / 2, y2 / 2, height + H);
	glVertex3f(x2 / 2, y2 / 2, 0 + H);
	glEnd();

	/** Draw the circle on top of cylinder */
	glColor3ub(R, G, B);
	glBegin(GL_LINES);
	angle = anBegin + DEGREE;
	while (angle < anEnd) {
		x = radius * cos(angle) * S;
		y = radius * sin(angle) * S;
		glVertex3f(x / 2, y / 2, height + H);
		glVertex3f(x, y, height + H);
		angle = angle + angle_stepsize;
	}
	glEnd();
}

