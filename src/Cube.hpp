#ifndef CCUBE_H
#define CCUBE_H

#include <GL/glut.h>


class Cube{
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat faceColor[6][3];
	GLuint textureID[6];

public:
	Cube();
	void draw(float i);
	void setTextureID(int index, int textureid);
private:
	void drawFace(int i);

};

#endif
