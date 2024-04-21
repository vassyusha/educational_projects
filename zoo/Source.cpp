#include "Zoo.h"
#include "mammal.h"
#include "fish.h"
#include "bird.h"

int main() {
	cat cat("kisa");
	zoo my_zoo;
	my_zoo.add(&cat);
	

	dog dog1("rex");
	my_zoo.add(&dog1);
	
	dog dog2("bobik");
	my_zoo.add(&dog2);

	parrot parrot("kesha");
	my_zoo.add(&parrot);

	fish fish("karas");
	my_zoo.add(&fish);

	my_zoo.sound();
	
	std::cout << my_zoo.countMam();
	
}