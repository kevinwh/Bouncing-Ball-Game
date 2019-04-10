#include "Square.hpp"


Square::Square() {
	x1 = 2.0;
	x2 = 5.0;
	y1 = 3.0;
	y2 = 5.0;
}

void Square::draw() {
   glBegin(GL_POLYGON);
      glVertex2i(x1,y1);
      glVertex2i(x2,y1);
      glVertex2i(x2,y2);
      glVertex2i(x1,y2);
   glEnd();
return;
}





