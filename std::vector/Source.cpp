#include "Vector.h"
#include <Windows.h>

int main() {

	std::cout << "constructor tests" << std::endl;

	Vector v;
	v.print();

	Vector v0(5);
	v0.print();

	int n = 5;
	double* k = new double[n];
	for (int i = 0; i < n; i++)k[i] = i + 1;
	Vector v1(n, k);
	v1.print();

	std::cout << "\noperator= tests" << std::endl;

	v = v1;
	//v1 = v = v0;
	//(v1 = v) = v0;
	v1 = v1;
	v.print();
	v0.print();
	v1.print();

	std::cout << "\noperator[] tests" << std::endl;

	std::cout << v1[2] << " ";
	v1[2] = 100;
	std::cout << v1[2] << std::endl;

	try {
		//std::cout << v1[5] << " ";
		v1[5] = 100;
		std::cout << v1[5] << std::endl;
	}
	catch (const char* exp) {
		std::cout << exp << std::endl;
	}

	std::cout << "\ntests of size, empty and swap methods" << std::endl;
	std::cout << v.size() << " " << v0.size() << " " << v1.size() << std::endl;
	std::cout << v.empty() << " " << v0.empty() << " " << v1.empty() << std::endl;
	
	try {
		v1.swap(1, 1);
		v1.swap(2, 3);
		v1.print();
		v.swap(0, 0);
	}
	catch (const char* exp) {
		std::cout << exp << std::endl;
	}

	system("pause");
	system("cls");

	std::cout << "push_back tests" << std::endl;
	for (int i = 0; i < n; i++) {
		v1.push_back(i);
		v1.print();
	}

	std::cout << "\npop_back tests" << std::endl;
	for (int i = 0; i < n; i++) {
		v1.pop_back();
		v1.print();
	}

	std::cout << "\ninsert tests" << std::endl;
	v1.insert(5, v0);
	v1.print();

	v1.insert(1, v1);
	v1.print();

	v1.insert(1, v1);
	v1.print();
	
	try {
		//v1.insert(-1, v0);
		v1.insert(41, v0);
	}
	catch (const char* exp) {
		std::cout << exp << std::endl;
	}

	std::cout << "\nerase tests" << std::endl;
	v1.erase(1, 20);
	v1.print();
	v1.erase(1, 10);
	v1.print();
	v1.erase(5, 5);
	v1.print();

	try {
		//v1.erase(-1, 6);
		v1.erase(2, 4);
	}
	catch (const char* exp) {
		std::cout << exp << std::endl;
	}
	
}