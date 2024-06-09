#include "Snake.h"

Snake::Snake() :size(1), dir(directions::RIGHT) {
	data = std::vector<std::vector<int>>(size, std::vector<int>(2));
	data[0][0] = data[0][1] = 0;
	state = alive;
}

void Snake::move(const Field& field) {
	for (int i = this->size - 1; i > 0; i--) {
		this->data[i][0] = this->data[i - 1][0];
		this->data[i][1] = this->data[i - 1][1];
	}
	switch (dir) {
	case directions::RIGHT:
		this->data[0][1] = (this->data[0][1] + 1 + field.getM())%field.getM();
		break;
	case directions::LEFT:
		this->data[0][1] = (this->data[0][1] - 1 + field.getM()) % field.getM();
		break;
	case directions::UP:
		this->data[0][0] = (this->data[0][0] - 1 + field.getN()) % field.getN();
		break;
	case directions::DOWN:
		this->data[0][0] = (this->data[0][0] + 1 + field.getN()) % field.getN();
		break;
	}
	for (int i = 1; i < this->size; i++) if (this->data[0] == this->data[i]) state = dead;
}

std::vector<int> Snake::next_move() {
	std::vector<int> next(2);
	switch (dir) {
	case RIGHT:
		next[0] = this->data[0][0];
		next[1] = this->data[0][1] + 1;
		break;
	case LEFT:
		next[0] = this->data[0][0];
		next[1] = this->data[0][1] - 1;
		break;
	case UP:
		next[0] = this->data[0][0] - 1;
		next[1] = this->data[0][1];
		break;
	case DOWN:
		next[0] = this->data[0][0] + 1;
		next[1] = this->data[0][1];
		break;
	}
	return next;
}

void Snake::treat() {
	this->size++;
	this->data.push_back(std::vector<int>(2));
}