#pragma once
#include "animal.h"
#include "mammal.h"
#include <vector>

class zoo
{
private:
	inline static int count = 0;
	std::vector<animal*> zoo;

public:
	void add(animal* a);
	void kick(int id);
	void sound();
	int countMam();
};

