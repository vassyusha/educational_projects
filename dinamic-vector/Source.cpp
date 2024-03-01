#include "Vector.h"
#include <Windows.h>

int main() {
	Vector v0(5);
	v0.print();
	double c[5] = { 1,2,3,4,5 };
	double k4[4] = { 1,1,1,1 };
	double k5[5] = { 1,1,1,1,1 };
	Vector v(5, c);
	v.print();
	Vector n4(4, k4);
	Vector n5(5, k5);
	try {
		v += n5;
		v.print();
		v += n4;
	}
	catch (const char* exc) {
		std::cout << exc << std::endl;
	}
	//n5 *= 5;
	n5.print();
	std::cout << v.norm() << " " << v.dist(v0) << " " << v.dot(v0) << " " << v.dot(n5);
	Sleep(100000000);
}