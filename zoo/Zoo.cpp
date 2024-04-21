#include "Zoo.h"

void zoo::add(animal* a) {
	this->zoo.push_back(a);
	count++;
}

void zoo::kick(int id) {
	for (auto i = this->zoo.begin(); i != this->zoo.end(); ++i) {
		if ((*i)->getId() == id) {
			this->zoo.erase(i);
			count--;
			break;
		}
	}
}

void zoo::sound() {
	for (auto i = this->zoo.begin(); i != this->zoo.end(); ++i) {
		(*i)->sound();
	}
}

int zoo::countMam() {
	int count = 0;
	for (auto i = this->zoo.begin(); i != this->zoo.end(); ++i) {
		mammal* pm = dynamic_cast<mammal*>(*i);
		if (pm != nullptr) count++;
	}
	return count;
}

