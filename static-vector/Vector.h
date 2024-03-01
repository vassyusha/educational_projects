#pragma once

#include <cmath>
#include <iostream>

class Vector
{
private:
	const int n = 10;
	double vect[10];

public:
	//constructors
	Vector() {
		for (int i = 0; i < n; i++)this->vect[i] = 0;
	}
	Vector(double* ne) {
		for (int i = 0; i < n; i++)this->vect[i] = ne[i];
	}

	//operators
	Vector operator-() const{//unary minus
		Vector v;
		for (int i = 0; i < n; i++) v.vect[i] = -this->vect[i];
		return v;
	}

	Vector operator+(const Vector & v) const {
		Vector c;
		for (int i = 0; i < n; i++) c.vect[i] = this->vect[i] + v.vect[i];
		return c;
	}
	Vector operator-(const Vector & v) const {//binary minus
		Vector c;
		return *this + (-v);
	}

	Vector operator+=(const Vector & v) {
		for (int i = 0; i < n; i++) this->vect[i] += v.vect[i];
		return *this;
	}
	Vector operator-=(const Vector & v) {
		for (int i = 0; i < n; i++) this->vect[i] -= v.vect[i];
		return *this;
	}

	Vector operator*(double a) const {
		Vector c;
		for (int i = 0; i < n; i++) c.vect[i] = this->vect[i] * a;
		return c;
	}
	Vector operator/(double a) const {
		Vector c;
		for (int i = 0; i < n; i++) c.vect[i] = this->vect[i] / a;
		return c;
	}

	Vector operator*=(double a) {
		for (int i = 0; i < n; i++) this->vect[i] *= a;
		return *this;
	}
	Vector operator/=(double a) {
		for (int i = 0; i < n; i++) this->vect[i] /= a;
		return *this;
	}

	//dot product
	double dot(const Vector & v) const{
		double sum = 0;
		for (int i = 0; i < n; i++) sum += (this->vect[i]) * (v.vect[i]);
		return sum;
	}

	//norm
	double getNorm() const{
		return sqrt(this->dot(*this));
	}

	//distance
	double dist(const Vector & v) const{
		return (*this - v).getNorm();
	}

	//print
	void print() {
		std::cout << "(";
		for (int i = 0; i < n - 1; i++) std::cout << this->vect[i] << ", ";
		std::cout << this->vect[n - 1] << ")" << std::endl;
	}
};

