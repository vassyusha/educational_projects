#pragma once

#include <iostream>
#include "default.h"

class Field
{
private:
	int n = 0;
	int m = 0;
	std::vector<std::vector<int>> field;
	std::vector<int> treat;

	inline void random() { srand(time(0)); }

public:

	Field(int n, int m);

	void fill(const Snake&);
	void show(int speed);
	std::vector<int> getTreat() const { return treat; }

	void newTreat(const Snake&);

	int getN() const { return this->n; }
	int getM() const { return this->m; }
};

