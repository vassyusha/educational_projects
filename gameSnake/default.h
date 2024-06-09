#pragma once

class Field;
class Snake;
#include <vector>
#include "Field.h"
#include "Snake.h"

#define no '.'
#define apple '*'
#define snake '>'


enum states {
	NO,
	APPLE,
	SNAKE
};