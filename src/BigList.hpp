#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#include <math.h>

#include "List.hpp"
#include "Random.hpp"

class BigList {

public:
	GLint type_list[5];
	Random myrList;
	List *Blist[5];
	BigList();
	~BigList();
	void drawBigList(GLfloat DEGREE, GLfloat H);
	void updateBigList();
	GLint statesCheck(GLfloat DEGREE);
};

