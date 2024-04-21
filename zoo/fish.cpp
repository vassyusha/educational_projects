#include "fish.h"

fish::fish(std::string name) : animal(name) {}

void fish::sound() {
	std::cout << "splish-splash" << std::endl;
}
void fish::swim() {
	std::cout << name << " is swimming, as usual" << std::endl;
}