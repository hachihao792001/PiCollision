#include "Render.h"
#include <sstream>
#include <chrono>
#include <thread>
using namespace chrono;

class Block {
public:
	long double mass;
	Vector2D v;
	MyRectangle rec;

	Block(long double _mass, Vector2D _v, MyRectangle _rec) {
		mass = _mass;
		v = _v;
		rec = _rec;
	}

	void updatePos() {
		rec.topLeftCorner.x += v.x;
		rec.topLeftCorner.y += v.y;
	}

	bool colliding(Block b) {
		return rec.CheckCollide(b.rec);
	}
};

string intToString(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

Block smallBlock(0.0001, { 0,0 }, MyRectangle({ 100,350 }, 50, 50));
Block bigBlock(1000000, { -0.0001,0 }, MyRectangle({ 300,200 }, 200, 200));

int collideCount = 0;

void Physic() {
	ll FPS = 30000000000;
	auto lastTime = high_resolution_clock::now();
	while (true) {
		if ((int)duration_cast<nanoseconds>(high_resolution_clock::now() - lastTime).count() >= (1.0 / FPS) * 1000000000.0) {
			if (smallBlock.colliding(bigBlock)) {
				long double m1 = smallBlock.mass;
				long double m2 = bigBlock.mass;
				long double v1 = smallBlock.v.x;
				long double v2 = bigBlock.v.x;
				smallBlock.v.x = (2 * m2 * v2 + (m1 - m2) * v1) / (m1 + m2);
				bigBlock.v.x = (2 * m1 * v1 + (m2 - m1) * v2) / (m1 + m2);
				collideCount++;
			}

			if (smallBlock.rec.topLeftCorner.x <= 0) {
				smallBlock.v.x = -smallBlock.v.x;
				collideCount++;
			}

			smallBlock.updatePos();
			bigBlock.updatePos();
			lastTime = high_resolution_clock::now();
		}
	}
}

void Render() {
	int FPS = 60;
	auto lastTime = high_resolution_clock::now();
	while (true) {
		if ((int)duration_cast<milliseconds>(high_resolution_clock::now() - lastTime).count() >= (1.0 / FPS) * 1000) {
			ClearScreen();

			DrawRectangle(smallBlock.rec, WHITE);
			DrawRectangle(bigBlock.rec, WHITE);

			DrawCustomText(intToString(collideCount), 600, 50);

			lastTime = high_resolution_clock::now();
		}
	}
}

int main() {
	thread physicThread(Physic);
	thread renderThread(Render);
	physicThread.join();
	renderThread.join();
}