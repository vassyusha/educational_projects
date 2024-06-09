#pragma once
#include "default.h"
#include <Windows.h>
#include <conio.h>
class Game
{
public:
	void start();
	void game(Field&, Snake&, int speed = 200);

	void click(Snake&);
	void end(const Snake&);
};

