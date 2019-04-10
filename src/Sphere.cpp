#include "Sphere.hpp"

Sphere::Sphere() {
	radius = 1.0;
	mode = MODE_WIRE;
	textureID = 0;
	splices = 50;
	stacks = 50;
	quad = gluNewQuadric();
}

Sphere::~Sphere() {
	gluDeleteQuadric(quad);
}

void Sphere::draw() {

	if (mode == MODE_WIRE) {
		glPushMatrix();
		this->ctmMultiply();
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		gluSphere(this->quad, radius, splices, stacks);
		glPopMatrix();
	}

	else if (mode == MODE_TEXTURE) {
		// add your implementation

	}


}

