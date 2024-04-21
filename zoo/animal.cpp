#include "animal.h"

animal::animal(std::string name):name(name), id(count++) {}

void animal::eat(std::string meal) {
	std::cout << name << " is eating " << meal << std::endl;
}
void animal::sleep() {
	std::cout << name << " is sleeping" << std::endl;
}

int animal::getId() {
	return this->id;
}