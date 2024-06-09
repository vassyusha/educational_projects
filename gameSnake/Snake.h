#pragma once
#include "default.h"

#define dead false;
#define alive true;

class Snake
{
public:
	enum directions {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
private:
	int size = 1;
	int dir = directions::RIGHT;
	std::vector<std::vector<int>> data;
	bool state = alive;

public:

	Snake();

	void changeDir(int direct) {if(this->dir/2 != direct/2) this->dir = direct; }
	void move(const Field&);
	std::vector<int> next_move();
	void treat();

	int getSize() const { return this->size; }
	std::vector<int> operator[](int i) const { return this->data[i]; }

	bool getState() const { return this->state; }
};

