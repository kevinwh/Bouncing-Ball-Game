#include "Ball.hpp"

Ball::Ball() {
	flag = 0;
	tx = 0.0;
	ty = 0.0;
	tz = 0.0;
	ball_x = 0.0;
	ball_y = 0.93;
	ball_z = 1.0;
	speed = 0.005;
	top = 1.4;
	base = 0.90;
	sound = 1;
}

void Ball::drawBall() {
	if (!flag) {
		sound = 1;
		ball_y += speed;
		if (ball_y >= top)
			flag = 1;
	}
	if (flag) {
		ball_y -= speed;
		if (ball_y <= base)
			flag = 0;
		// =0
	}
}

