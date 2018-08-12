#include "stdafx.h"
#include "Ball.h"
#include <ctime>

Ball::Ball() {}

Ball::Ball(double x, double y, unsigned int t) : _x(x), _y(y), _t(t) {
	srand(time(NULL));
	const int Vscale = 100; //1 m = 0.01 pixels.
	const double Mmin = 1., Mmax = 10., Vmin = 1., Vmax = 100.;
	_v = Rand(Vmin, Vmax) / Vscale;
	//_m = Rand(Mmin, Mmax);
	if (t == 1) _m = 1.;
	else _m = 2.;
	_direction = std::make_pair(Rand(-1., 1.), Rand(-1., 1.));
}

double Ball::Rand(double min, double max) const {
	return min + (max - min) * (double)rand() / RAND_MAX;
}

void Ball::Colscr() {
	//The direction is the pair of cos(first) and sin(second) of the angle at which the ball moves to the horizon. 
	if (_y >= 0.5) _direction = std::make_pair(_direction.first, -_direction.second); //Top screen.
	else if (_y <= -0.5) _direction = std::make_pair(_direction.first, -_direction.second); //Down screen.
	if (_x >= 0.5) _direction = std::make_pair(-_direction.first, _direction.second); //Right screen.
	else if (_x <= -0.5) _direction = std::make_pair(-_direction.first, _direction.second); //Left screen.
}

void Ball::Collision(Ball& ball) {
	if (fabs(this->_x - ball._x) <= 0.03 && fabs(this->_y - ball._y) <= 0.03) {
		/*double alfa0 = atan(fabs(this->_y - ball._y) / fabs(this->_x - ball._x)), V1x = this->_v * this->_direction.first, V1y = this->_v * this->_direction.second, V2x = ball._v * ball._direction.first, V2y = ball._v * ball._direction.second;
		double V1n = V1x * cos(alfa0) - V1y * sin(alfa0), V1t = V1x * cos(alfa0) + V1y * sin(alfa0), V2n = V2x * cos(alfa0) - V2y * sin(alfa0), V2t = V2x * cos(alfa0) + V2y * sin(alfa0);

		V1n = this->_m * V1n + ball._m * V2n + (V2n - V1n) * ball._m;
		V2n = this->_m * V1n + ball._m * V2n - (V2n - V1n) * this->_m;

		this->_v = sqrt(V1n * V1n + V1t * V1t);
		ball._v = sqrt(V2n * V2n + V2t * V2t);

		V1x = V1n * cos(alfa0) - V1t * sin(alfa0);
		V1y = V1n * sin(alfa0) + V1t * cos(alfa0);
		V2x = V2n * cos(alfa0) - V2t * sin(alfa0);
		V2y = V2n * sin(alfa0) + V2t * cos(alfa0);

		if (this->_direction.first >= 0 && this->_direction.second >= 0) this->_direction = std::make_pair(V1x * this->_direction.first / this->_v, V1x * this->_direction.second / this->_v);
		else if (this->_direction.first < 0 && this->_direction.second >= 0) this->_direction = std::make_pair(-V1x * this->_direction.first / this->_v, V1x * this->_direction.second / this->_v);
		else if (this->_direction.first < 0 && this->_direction.second < 0) this->_direction = std::make_pair(-V1x * this->_direction.first / this->_v, -V1x * this->_direction.second / this->_v);
		else if (this->_direction.first >= 0 && this->_direction.second < 0) this->_direction = std::make_pair(V1x * this->_direction.first / this->_v, -V1x * this->_direction.second / this->_v);

		else if (ball._direction.first >= 0 && ball._direction.second >= 0) ball._direction = std::make_pair(V2x * ball._direction.first / ball._v, V2x * ball._direction.second / ball._v);
		else if (ball._direction.first < 0 && ball._direction.second >= 0) ball._direction = std::make_pair(-V2x * ball._direction.first / ball._v, V2x * ball._direction.second / ball._v);
		else if (ball._direction.first < 0 && ball._direction.second < 0) ball._direction = std::make_pair(-V2x * ball._direction.first / ball._v, -V2x * ball._direction.second / ball._v);
		else if (ball._direction.first >= 0 && ball._direction.second < 0) ball._direction = std::make_pair(V2x * ball._direction.first / ball._v, -V2x * ball._direction.second / ball._v);*/
	}
}

void Ball::Move() {
	const double dt = 1e-3;
	_x += _v * _direction.first * dt;
	_y += _v * _direction.second * dt;
}

Ball::~Ball() {}