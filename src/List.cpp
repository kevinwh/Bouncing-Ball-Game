#include "List.hpp"

List::List() {
	type = 0;
	for (int i = 0; i < 8; i++) {
		list[i] = new Layer();
	}
}

List::~List() {
	for (int i = 0; i < 8; i++) {
		delete list[i];
	}
}

void List::drawList(GLfloat DEGREE, GLfloat H, GLint r) {
	int gNumber;
	//r = rand() % 100;
	if (r % 2 == 0)	gNumber = 2;
	else gNumber = 1;
	//gNumber = 2;
	if (gNumber == 1) {
		type = 1;
		list[0]->draw(DEGREE, r * 3.6 - 60 - 90, r * 3.6 - 90, 153, 255, 102,
				H);
		list[1]->draw(DEGREE, r * 3.6 - 90, r * 3.6 + 120 - 90, 100, 100, 100,
				H);
		list[2]->draw(DEGREE, r * 3.6 + 120 + 75 - 90,
				r * 3.6 + 120 + 75 + 60 - 90, 100, 100, 100, H);
		// fall part:(empty) r+120~r+195  r+255~r+300
		// fail part:(green) r+300~r+360
		// safe part:(balck) r~r+120  r+195~r+255
	} else {
		type = 2;
		list[0]->draw(DEGREE, r * 3.6 - 60- 90, r * 3.6- 90, 153, 255, 102, H);
		list[1]->draw(DEGREE, r * 3.6 - 180- 90, r * 3.6 - 120- 90, 153, 255, 102, H);
		list[2]->draw(DEGREE, r * 3.6 - 120- 90, r * 3.6 - 60- 90, 100, 100, 100, H);
		list[3]->draw(DEGREE, r * 3.6- 90, r * 3.6 + 60- 90, 100, 100, 100, H);
		list[4]->draw(DEGREE, r * 3.6 - 240- 90, r * 3.6 - 180- 90, 100, 100, 100, H);
		// fall part:(empty) r+60~r+120
		// fail part:(green) r+180~r+240  r+300~r+360
		// safe part:(balck) r~r+60  r+120~r+180  r+240~r+300

	}
	// normal 100, 100, 100
	// trap 153, 255, 102
}

