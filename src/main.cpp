/*#include <GL/glew.h>
#include <GL/glut.h>
#include "GL/glaux.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <GL/GL.h>

#include "Cylinder.hpp"
#include "BigList.hpp"
#include "Ball.hpp"

BigList myBigList;
Cylinder myCylinder;
Ball myBall;
GLfloat layer_speed = 0.0;
GLint winWidth = 1200, winHeight = 800, state = 1, k = 1.0, move = 1;
GLfloat xBegin, a, b;
GLint dis = 0.0, DEGREE;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, -1.0, -3.0);
	glRotatef(-55, 1.0, 0.0, 0.0);
	myCylinder.draw();

	if (state == 2 && move == 1) { // fall
		k = 0.5;
		move = 0;
		myBall.base = 0.00;
		myBall.flag = 1;
	} else if (state == 0) { // green
		myBigList.drawBigList(dis / 10 * 6, 0);
		//myBall.speed = 0;
	} else if (state == 1) {
		myBigList.drawBigList(dis / 10 * 6, 0);
	}

	if (k <= 0.5 && state == 2) {
		myBigList.drawBigList(dis / 10 * 6, 0 + (0.5 - k));
		k -= 0.01;
	}
	if (k <= 0.0 && state == 2) {
		k = 1.0;
		myBigList.updateBigList();
		move = 1;
		state = 1;
		//myBigList.drawBigList(dis / 10 * 6, 0);
	}

	if (k<= 0.23) myBall.base = 0.93;

	//myBigList.drawBigList(dis / 10 * 6, 0);
	a = floorf(myBall.ball_y * 10000) / 10000;
	b = floorf(myBall.base * 10000) / 10000;
	if (a == b) {
		state = myBigList.statesCheck(dis / 10 * 6);
		printf("%d %d %f\n", state, move, k);
	}

	glPushMatrix();
	glColor3f(0, 0, 1);
	glRotatef(55, 1.0, 0.0, 0.0);
	glTranslatef(myBall.ball_x, myBall.ball_y, myBall.ball_z + 0.6);
	glutSolidSphere(0.025, 23, 23);
	glPopMatrix();
	myBall.drawBall();

	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
	gluPerspective(40.0, (GLdouble) newWidth / (GLdouble) newHeight, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, newWidth, newHeight);
	glFlush();
}

void mouseAction(int button, int state, int xMouse, int yMouse) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		xBegin = xMouse;
		//printf("%f\n",xBegin);
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		dis += (xMouse - xBegin);
		//printf("%d\n",xMouse);
	}
	glutPostRedisplay();
	glFlush();
}

void mouseMotion(GLint xMouse, GLint yMouse) {
	dis += (xMouse - xBegin);
	xBegin = xMouse;
	glutPostRedisplay();
	glFlush();
}

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Lonely God and Dragon Fruit :3");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glewInit();

	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(winReshapeFcn);

	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
// if we need right click to pause
//glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}*/

