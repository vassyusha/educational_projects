#include "Field.h"
#include <Windows.h>
#include <ctime>

Field::Field(int n, int m) : n(n), m(m) {
	field = std::vector<std::vector<int>>(n, std::vector<int>(m));
	this->random();
	treat = std::vector<int>(2);
	treat[0] = 0;
	treat[1] = 1;
}

void Field::fill(const Snake& sn) {
	field = std::vector<std::vector<int>>(n, std::vector<int>(m));
	this->field[this->treat[0]][this->treat[1]] = APPLE;
	for (int p = 0; p < sn.getSize(); p++) {
		int i = sn[p][0];
		int j = sn[p][1];
		this->field[i][j] = states::SNAKE;
	}
}

void Field::show(int speed) {
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->m; j++) {
			switch (this->field[i][j]) {
			case states::NO:
				std::cout << no;
				break;
			case states::APPLE:
				SetConsoleTextAttribute(hConsole, 4);
				std::cout << apple;
				SetConsoleTextAttribute(hConsole, 7);
				break;
			case states::SNAKE:
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << snake;
				SetConsoleTextAttribute(hConsole, 7);
				break;
			default:
				break;
			}
		}
		std::cout << std::endl;
	}
	Sleep(speed);
}

void Field::newTreat(const Snake& sn) {
	bool flag = true;
	this->treat[0] = rand() % n;
	this->treat[1] = rand() % m;

	while (flag){
		flag = false;
		for (int i = 0; i < sn.getSize(); i++) {
			if (sn[i] == treat) {
				flag = true;
				break;
			}
		}
		if (flag) {
			this->treat[0] = rand() % n;
			this->treat[1] = rand() % m;
		}
	}

}