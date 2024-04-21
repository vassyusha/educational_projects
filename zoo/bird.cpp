#include "bird.h"

bird::bird(std::string name) : animal(name) {}

void bird::sound() {
	std::cout << name << " is chirping" << std::endl;
}

parrot::parrot(std::string name) : bird(name){}

void parrot :: parody() {
	std::cout << name << " is parodying again" <</*an.name <<*/ std::endl;
}