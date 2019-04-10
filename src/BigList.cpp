#include "BigList.hpp"

BigList::BigList() {
	for (int i = 0; i < 5; i++) {
		Blist[i] = new List();
	}
}

BigList::~BigList() {
	for (int i = 0; i < 5; i++) {
		delete Blist[i];
	}
}

void BigList::drawBigList(GLfloat DEGREE, GLfloat H) {
	//Blist[0]->initial(DEGREE, 1.3);
	//myrList.rList[0] = 0;
	Blist[0]->drawList(DEGREE, H + 1.3, myrList.rList[0]);
	type_list[0] = Blist[0]->type;
	Blist[1]->drawList(DEGREE, H + 0.8, myrList.rList[1]);
	type_list[1] = Blist[1]->type;
	Blist[2]->drawList(DEGREE, H + 0.3, myrList.rList[2]);
	type_list[2] = Blist[2]->type;
	Blist[3]->drawList(DEGREE, H - 0.2, myrList.rList[3]);
	type_list[3] = Blist[3]->type;
	Blist[4]->drawList(DEGREE, H - 0.7, myrList.rList[4]);
	type_list[4] = Blist[4]->type;

//	Blist[0]->drawList(DEGREE, H + 1.3, 25/3.6);
//	Blist[0]->drawList(DEGREE, H + 0.8, 25/3.6);
//	Blist[0]->drawList(DEGREE, H + 0.3, 25/3.6);
//	Blist[0]->drawList(DEGREE, H - 0.2, 25/3.6);
//	Blist[0]->drawList(DEGREE, H - 0.7, 25/3.6);

}

void BigList::updateBigList() {
	Blist[0] = Blist[1];
	myrList.rList[0] = myrList.rList[1];
	type_list[0] = type_list[1];
	//Blist[0]->type = Blist[1]->type;

	Blist[1] = Blist[2];
	myrList.rList[1] = myrList.rList[2];
	type_list[1] = type_list[2];
	//Blist[1]->type = Blist[2]->type;

	Blist[2] = Blist[3];
	myrList.rList[2] = myrList.rList[3];
	type_list[2] = type_list[3];
	//Blist[2]->type = Blist[3]->type;

	Blist[3] = Blist[4];
	myrList.rList[3] = myrList.rList[4];
	type_list[3] = type_list[4];
	//Blist[3]->type = Blist[4]->type;

	int seed = time(NULL);
	srand(seed);
	myrList.rList[4] = rand() % 100;
	Blist[4]->drawList(0, -0.7, myrList.rList[4]);
	type_list[4] = Blist[4]->type;
}

GLint BigList::statesCheck(GLfloat DEGREE) {
	int r = myrList.rList[0]*3.6;
	//int r = 25;
	if (DEGREE < 0) {
		DEGREE = labs(DEGREE)%360;
	}
	else {
	    DEGREE = 360 - fmod(DEGREE, 360);
	}
	//printf("Degree: %f\n", DEGREE);
	DEGREE = fmod(DEGREE + (360 - r), 360);
	if (type_list[0] == 1) {
		if ((DEGREE  < 195 -2  && DEGREE> 120 + 2 ) || (DEGREE> 255 + 2  && DEGREE < 300 - 2)) {
				//printf("1  %d  fall", DEGREE);
		    return 2;
		}
		else if (DEGREE >= 300 - 2  && DEGREE < 360 + 2) {
				//printf("1  %d  green", DEGREE);
		    return 0;	// green
		}
			//printf("1  %d  bouncing", DEGREE);
		    return 1;
	}
	else if (type_list[0] == 2) {
		if (DEGREE < 120 - 2  && DEGREE > 60 + 2) {
			return 2;
		}
		else if ((DEGREE < 240 + 2 && DEGREE > 180 - 2) || (DEGREE >300-2 && DEGREE < 360+2)) {
		    return 0;	// green
		}
		return 1;
	}
	else {
		printf("NONONONONO\n");
	}
}

