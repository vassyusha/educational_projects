#include "Game.h"

void Game::start() {
	system("cls");
	int n, m;
	std::cout << "choose game mode: 1 - hard; 2 - medium; 3 - easy\n";
	int speed;
	std::cin >> speed;
	speed *= 100;
	std::cout << "input sizes of the field: ";
	std::cin >> n >> m;
	Field field(n, m);
	Snake sn;
	game(field, sn, speed);
}

void Game::click(Snake& sn) {
	if (_kbhit()) {
		char g = _getch();
		switch (g) {
		case 'w':
			sn.changeDir(Snake::directions::UP);
			break;
		case 's':
			sn.changeDir(Snake::directions::DOWN);
			break;
		case 'd':
			sn.changeDir(Snake::directions::RIGHT);
			break;
		case 'a':
			sn.changeDir(Snake::directions::LEFT);
			break;
		default:
			system("pause");
			break;
		}
	}
}

void Game::game(Field& field, Snake& sn, int speed) {
	while (sn.getState()) {

		this->click(sn);

		if (sn.next_move() == field.getTreat()) {
			sn.treat();
			field.newTreat(sn);
		}
		sn.move(field);
		field.fill(sn);
		field.show(speed);
	}
	system("cls");
	end(sn);
}

void Game::end(const Snake& sn) {
	std::cout << "game over\n";
	std::cout << "size of your snake: " << sn.getSize() << "\n";
	std::cout << "if you want to try again press enter\npress smth else, if you want to close the game";
	if (_getch() == 13)start();
}