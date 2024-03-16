#include "matrix.h"
#include <Windows.h>

int main() {
	double** pr = new double*[3];
	for (int i = 0; i < 3; i++) {
		pr[i] = new double[3];
		for (int j = 0; j < 3; j++) pr[i][j] = i + j;
	}
	std::cout << "constructor tests" << std::endl;
	matrix m0;
	m0.init();
	m0.print();
	matrix m1(3, 3, pr);
	m1.print();
	matrix m2(3, 3);
	m2.print();
	matrix m;
	m.print();
	for (int i = 0; i < 3; i++) delete[] pr[i];
	delete[] pr;
	system("pause");
	system("cls");

	std::cout << "operator () tests" << std::endl;
	std::cout << m1(2, 2) << std::endl;
	m1(2, 2) = 2;
	m1.print();
	system("pause");
	system("cls");

	std::cout << "operators */*=matrix tests" << std::endl;
	try {
		m = m0 * m1;
		m1.print();
		m1 *= m1;
		m.print();
		m0.print();
		m1.print();
	}
	catch (const char* expl) {
		std::cout << expl << std::endl;
	}
	system("pause");
	system("cls");

	std::cout << "operator= tests" << std::endl;
	m1 = m0;
	//m2 = m1 = m0;
	//(m2 = m1) = m0;
	//m0 = m0;
	m0.print();
	m1.print();
	m2.print();
	system("pause");
	system("cls");
	std::cout << "determinant tests " << std::endl;
	try {
		std::cout << m0.det() << " " << m.det() << " " << m1.det() << std::endl;
	}
	catch (const char* expl) {
		std::cout << expl << std::endl;
	}
	system("pause");
	system("cls");
	std::cout << "operators +/+= tests" << std::endl;
	try {
		//m0 += m1 += m2;
		//m0 += m0;
		(m0 += m2) += m1;
		m0.print();
		m1.print();
		m2.print();
	}
	catch (const char* expl) {
		std::cout << expl << std::endl;
	}
	try {
		m0 = m1 + m2;
		m0.print();
		m1.print();
		m2.print();
	}
	catch (const char* expl) {
		std::cout << expl << std::endl;
	}
	system("pause");
	system("cls");

	std::cout << "operators */*=const tests + operator /= tests" << std::endl;
	//m0 *= 2;
	(m0 *= 2) *= -1;
	m0.print();
	m1.print();
	m2.print();
	
	m0 = m1 * 4;
	m0.print();
	m1.print();
	m2.print();
	try {m0 /= 0;}
	catch (const char* expl) {
		std::cout << expl << std::endl;
	}
	
	system("pause");
	system("cls");

	std::cout << "operarors -/-= tests" << std::endl;
	try {
		(-m0).print();
		m0 -= m1 -= m2;
		//m0 -= m0;
		//(m0 -= m2) -= m1;
		m0.print();
		m1.print();
		m2.print();
	}
	catch (const char* expl) {
		std::cout << expl << std::endl;
	}
	try {
		m0 = m1 - m2;
		m0.print();
		m1.print();
		m2.print();
	}
	catch (const char* expl) {
		std::cout << expl << std::endl;
	}
	system("pause");
	system("cls");
	
	std::cout << "transposition tests" << std::endl;
	m0.print();
	m0.transpose();
	m0.print();
	m0.transposed().print();
	system("pause");
	system("cls");

	
}