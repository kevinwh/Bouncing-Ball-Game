#include "Cube.hpp"

Cube::Cube() {
	vertex[0][0] = -1;
	vertex[0][1] = -1;
	vertex[0][2] = -1;

	vertex[1][0] = -1;
	vertex[1][1] = 1;
	vertex[1][2] = -1;

	vertex[2][0] = 1;
	vertex[2][1] = 1;
	vertex[2][2] = -1;

	vertex[3][0] = 1;
	vertex[3][1] = -1;
	vertex[3][2] = -1;

	vertex[4][0] = -1;
	vertex[4][1] = -1;
	vertex[4][2] = -0.5;

	vertex[5][0] = -1;
	vertex[5][1] = 1;
	vertex[5][2] = -0.5;

	vertex[6][0] = 1;
	vertex[6][1] = 1;
	vertex[6][2] = -0.5;

	vertex[7][0] = 1;
	vertex[7][1] = -1;
	vertex[7][2] = -0.5;

	face[0][0] = 0;
	face[0][1] = 1;
	face[0][2] = 2;
	face[0][3] = 3;

	face[1][0] = 7;
	face[1][1] = 6;
	face[1][2] = 5;
	face[1][3] = 4;

	face[2][0] = 0;
	face[2][1] = 4;
	face[2][2] = 5;
	face[2][3] = 1;

	face[3][0] = 2;
	face[3][1] = 1;
	face[3][2] = 5;
	face[3][3] = 6;

	face[4][0] = 3;
	face[4][1] = 2;
	face[4][2] = 6;
	face[4][3] = 7;

	face[5][0] = 0;
	face[5][1] = 3;
	face[5][2] = 7;
	face[5][3] = 4;
}

void Cube::drawFace(int i) {
	glBindTexture(GL_TEXTURE_2D, textureID[i]);
	glBegin(GL_QUADS); //face -> texture face
	glTexCoord2f(0.0, 0.0);
	glVertex3fv(&vertex[face[i][0]][0]);
	glTexCoord2f(1.0, 0.0);
	glVertex3fv(&vertex[face[i][1]][0]);
	glTexCoord2f(1.0, 1.0);
	glVertex3fv(&vertex[face[i][2]][0]);
	glTexCoord2f(0.0, 1.0);
	glVertex3fv(&vertex[face[i][3]][0]);
	glEnd();

}

void Cube::draw(float i) {
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glRotatef(55, 1.0, 0.0, 0.0);
	glTranslatef(11+i, 17, 1);
	glColor3f(1, 1, 1);
	drawFace (1);

	glPopMatrix();
}

void Cube::setTextureID(int index, int textureid) {
	textureID[index] = textureid;
}
