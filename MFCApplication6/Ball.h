#pragma once
#include <utility>

class Ball {
private:
	double _x;
	double _y;
	double _m;
	double _v;
	unsigned int _t;
	std::pair<double, double> _direction;
public:
	Ball();
	Ball(double, double, unsigned int);
	void Colscr(); //Collision with window's frame detection.
	void Collision(Ball&); //Collision with other balls detection.
	void Move(); //Moves the balls.
	double Rand(double, double) const; //Gives random real number from max to min.
	friend void qSort(int); //Sorts the array of balls.
	friend void Scene(); //Draws the balls.
	~Ball();
};