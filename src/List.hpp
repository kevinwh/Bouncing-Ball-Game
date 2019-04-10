#include <iostream>
#include <list>
#include <vector>
#include "Layer.hpp"


class List {

public:
	Layer *list[8];
	GLint type;
	GLfloat Height;
	List();
	~List();
	void drawList(GLfloat DEGREE, GLfloat H, GLint r);
};

