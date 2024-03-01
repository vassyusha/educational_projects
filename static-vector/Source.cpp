#include "Vector.h"

int main() {

	Vector v0;
	v0.print();
	double nw[10] = {1,2,3,4,5,6,7,8,9,10};
	Vector v1(nw);
	v1.print();
	Vector v = v1;
	(-v).print();
	(v - v).print();
	(v + v).print();
	(v * 2).print();
	(v / 2).print();
	v /=2;
	v.print();
	std::cout << v.dist(v1) << std::endl;
	std::cout << v.getNorm() << std::endl;
	std::cout << v.dot(v1) << " " << v.dot(v0) << std::endl;
	return 0;
}