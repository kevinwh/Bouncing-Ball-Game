#include <GL/glew.h>
#include <GL/glut.h>
#include "GL/glaux.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <GL/GL.h>
#include <windows.h>
#include <mmsystem.h>

#include "Cylinder.hpp"
#include "BigList.hpp"
#include "Ball.hpp"
#include "Cube.hpp"

BigList myBigList;
Cylinder myCylinder;
Ball myBall;
Cube myCube;
GLint winWidth = 1200, winHeight = 800, state = 1, count = 0;
GLfloat xBegin, a, b, k = 1.0;
GLint dis = 0.0, DEGREE, move = 1, Rotate = 1, pause = 0;

void *font = GLUT_BITMAP_HELVETICA_18;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	glFlush();
}

void output(float x, float y, char *string) {
	int len, i;
	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

void reset_game() {
	//reset = 0;
	dis = 0.0;
	state = 1;
	move = 1;
	Rotate = 1;
	myBall.ball_x = 0.0;
	myBall.ball_y = 0.93;
	myBall.ball_z = 1.0;
	myBall.speed = 0.005;
	myBall.top = 1.4;
	myBall.base = 0.90;
	k = 1.0;
	count = 0;
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
		myBall.base = 0.78;
		myBall.flag = 1;
	} else if (state == 0) { // green
		PlaySound("lose.wav", NULL, 1);
		myBigList.drawBigList(dis / 10 * 6, 0);
		myBall.speed = 0;
		Rotate = 0;

	} else if (state == 1) {
		myBigList.drawBigList(dis / 10 * 6, 0);
	}

	if (k <= 0.5 && state == 2) {
		myBigList.drawBigList(dis / 10 * 6, 0 + (0.5 - k));
		k -= 0.01;
		myBall.sound = 0;
	}
	if (k <= 0.0 && state == 2) {
		k = 1.0;
		myBigList.updateBigList();
		count++;
		//printf("Points: %d\n", count);
		move = 1;
		state = 1;
	}

	if (k <= 0.23)
		myBall.base = 0.93;

	a = floorf(myBall.ball_y * 10000) / 10000;
	b = floorf(myBall.base * 10000) / 10000;
	if (a == b) {
		state = myBigList.statesCheck(dis / 10 * 6);
		if (state == 1 && myBall.sound == 1)
			PlaySound("3.wav", NULL, 1);
	}

	if (myBall.ball_y == 0.93)
		state = myBigList.statesCheck(dis / 10 * 6);

	glPushMatrix();
	glColor3f(0, 0, 1);
	glRotatef(55, 1.0, 0.0, 0.0);
	glTranslatef(myBall.ball_x, myBall.ball_y, myBall.ball_z + 0.6);
	glutSolidSphere(0.03, 23, 23);
	glPopMatrix();
	myBall.drawBall();

//	myCube.draw(0);
//	myCube.draw(2.5);

	glColor3f(1, 1, 1);
	char text[100];
	sprintf(text, "Your score:   %d", count);
	output(-3.5, 5.5, text);

	glColor3f(1, 0, 0);
	char text1[100];
	sprintf(text1, "RESET");
	output(2.6, 5.5, text1);

	glColor3f(1, 0, 0);
	char text2[100];
	if(pause)	sprintf(text2, " PLAY");
	else	sprintf(text2, "PAUSE");
	output(3.2, 5.5, text2);

	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
	gluPerspective(40.0, (GLdouble) newWidth / (GLdouble) newHeight, 0.5, 20.0);
	//gluOrtho2D(0.0, GLdouble(newWidth), GLdouble(newHeight), 0.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, newWidth, newHeight);
	glFlush();
}

void mouseAction(int button, int state, int xMouse, int yMouse) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		xBegin = xMouse;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		if (Rotate == 1) {
			dis += (xMouse - xBegin);
		}
		//printf("x:%d y:%d\n", xMouse, yMouse);
		if (xMouse < 1070 && xMouse > 990 && yMouse < 105 && yMouse > 30) {
			reset_game();
		}
		if (xMouse < 1170 && xMouse > 1090 && yMouse < 105 && yMouse > 30) {
			if (pause) {
				myBall.speed = 0.005;
				Rotate = 1;
				pause = 0;
			} else {
				myBall.speed = 0;
				Rotate = 0;
				pause = 1;
			}
		}
	}
	glutPostRedisplay();
	glFlush();
}

void mouseMotion(GLint xMouse, GLint yMouse) {
	if (Rotate == 1) {
		dis += (xMouse - xBegin);
	}
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
	glutMainLoop();

	return 0;
}

