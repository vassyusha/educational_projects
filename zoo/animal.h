#include <string>
#include <iostream>
#pragma once
class animal
{
protected:
	inline static int count = 0;
	std::string name;
	int id = -1;

public:
	animal(std::string name);

	int getId();

	void eat(std::string meal = "");
	void sleep();
	virtual void sound() = 0;

	virtual ~animal(){}
	
};

