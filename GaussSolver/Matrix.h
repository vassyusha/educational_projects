#pragma once
#include <iostream>
#include "VectorTemplate.h"

class Matrix {
private:
	int n, m;
	VectorTemplate<VectorTemplate<double>> data;
public:
	Matrix(int n, int m) :n(n), m(m), data(n, VectorTemplate<double>(m, 0)) {}

	double& operator()(int i, int j) { return this->data[i][j]; }

	double operator()(int i, int j) const{ return this->data[i][j]; }

	VectorTemplate<double>& operator[](int ind) {
		if (ind < 0) throw "incorrect index";
		return this->data[ind];
	}

	VectorTemplate<double> operator[](int ind) const {
		if (ind < 0) throw "incorrect index";
		return this->data[ind];
	}

	int getn() const { return this->n; }
	int getm() const { return this->m; }


	friend std::ostream& operator << (std::ostream& ostr, const Matrix& a) {
		for (int i = 0; i < a.n; i++) ostr << a.data[i] << "\n";
		return ostr;
	}

	friend std::istream& operator >> (std::istream& istr, Matrix& a) {
		for (int i = 0; i < a.n; i++) {
			for (int j = 0; j < a.m; j++) istr >> a(i, j);
		}
		return istr;
	}

};