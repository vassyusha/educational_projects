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
	
	std::cout << "\niterator tests" << std::endl;

	Vector::iterator it1 = v1.begin();
	Vector::iterator it2 = it1 + 1;

	it1.print();
	it2.print();

	std::cout << (it1 < it2) << " " << (v.begin() < v.end()) << " " << (it2 < it1) << std::endl;
	std::cout << (it1 > it2) << " " << (v.begin() > v.end()) << " " << (it2 > it1) << std::endl;
	std::cout << (it1 >= it2) << " " << (v.begin() >= v.end()) << " " << (it2 >= it1) << std::endl;
	std::cout << (it1 <= it2) << " " << (v.begin() <= v.end()) << " " << (it2 <= it1) << std::endl;
	std::cout << (it1 == it2) << " " << (v.begin() == v.end()) << std::endl;
	std::cout << (it1 != it2) << " " << (v.begin() != v.end()) << std::endl << std::endl;

	std::cout << ((it2 + 3) - it1) << std::endl;
	(it1 -= 3).print();
}