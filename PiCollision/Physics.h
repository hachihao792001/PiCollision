#pragma once
#define WIDTH 960
#define HEIGHT 600
#define PLAYER_SIZE 100
#define PLAYER_THICKNESS 20
#define PLAYER_MOVESPEED 10
#define BALL_SIZE 12
#define BALL_SPEED 10
#define DIST_PLAYER_BORDER 70
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
typedef unsigned long long int ll;

struct Pos {
	long double x, y;
};

struct Vector2D {
	long double x, y;
	double getMagnitude() {
		return  sqrt(x * x + y * y);
	}
	void setMagnitude(double magnitude) {
		double currentMagnitude = getMagnitude();
		x = (int)((double)x / currentMagnitude * magnitude);
		y = (int)((double)y / currentMagnitude * magnitude);
	}
	void print() {
		cout << x << " " << y << endl;
	}
};

class MyRectangle {
public:
	Pos topLeftCorner;
	ll width, height;

	MyRectangle() {

	}

	MyRectangle(Pos p, int w, int h) {
		topLeftCorner = p;
		width = w;
		height = h;
	}

	void print() {
		cout << topLeftCorner.x << " " << topLeftCorner.y << endl;
	}

	bool CheckCollide(MyRectangle rec) {

		// Nếu 1 hình chữ nhật nằm phía bên trái hình chữ nhật kia 
		if (topLeftCorner.x >= rec.topLeftCorner.x + rec.width ||
			rec.topLeftCorner.x >= topLeftCorner.x + width)
			return false;

		// Nếu 1 hình chữ nhật nằm phía bên trên hình chữ nhật kia
		if (topLeftCorner.y >= rec.topLeftCorner.y + rec.height ||
			rec.topLeftCorner.y >= topLeftCorner.y + height)
			return false;
		return true;
	}
};