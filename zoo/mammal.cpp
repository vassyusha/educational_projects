#include "mammal.h"

mammal::mammal(std::string name) : animal(name){}
void mammal::play(const mammal& fr) {
	std::cout << name << " is playing with " << fr.name << std::endl;
}

cat::cat(std::string name): mammal(name){}
void cat::sound() {
	std::cout << name << " is meowing" << std::endl;
}
void cat::scratch(std::string stuff) {
	std::cout << name << " is scratching " << stuff << std::endl;
}

dog::dog(std::string name) : mammal(name) {}
void dog::sound() {
	std::cout << name << " is woofing" << std::endl;
}
void dog::guard(std::string thing) {
	std::cout << name << " is guarding " << thing << std::endl;
}

fox::fox(std::string name) : mammal(name) {}
void fox::sound() {
	std::cout << name << " is barking" << std::endl;
}
void fox::plot() {
	std::cout << name << " is plotting something" << std::endl;
}