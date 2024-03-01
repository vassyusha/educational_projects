#pragma once
#include <iostream>
#include <cmath>

class Vector
{
private:
	int n = 0;
	double* vect = nullptr;
public:
	//usual constructor
	Vector(int dim, double* v = nullptr) {
		if (dim < 0) throw "incorrect dim";
		if (dim == 0) return;
		if (v == nullptr) {
			this->n = dim;
			this->vect = new double[this->n];
			for (int i = 0; i < this->n; i++)this->vect[i] = 0;
		}
		else {
			this->n = dim;
			this->vect = new double[this->n];
			for (int i = 0; i < n; i++) this->vect[i] = v[i];
		}
	}
	
	//copy constructor
	Vector(const Vector& v):n(v.n) {
		this->vect = new double[this->n];
		for (int i = 0; i < this->n; i++)this->vect[i] = v.vect[i];
	}

	//operator =
	Vector operator=(const Vector& v) {
		if (this == &v) return *this;
		this->n = v.n;
		delete[] this->vect;
		this->vect = new double[this->n];
		for (int i = 0; i < this->n; i++)this->vect[i] = v.vect[i];
		return *this;
	}

	//destructor
	~Vector() {
		delete[] this->vect;
	}

	//operators
	Vector operator-() const{
		Vector c(this->n);
		for (int i = 0; i < this->n; i++)c.vect[i] = -(this->vect[i]);
		return c;
	}

	Vector operator+=(const Vector& v) {
		if(this->n != v.n) throw "different dim";
		for (int i = 0; i < this->n; i++) this->vect[i] += v.vect[i];
		return *this;
	}
	Vector operator+(const Vector& v) const {
		Vector c(this->n, this->vect);
		c += v;
		return c;
	}
	
	Vector operator-=(const Vector& v) {
		if (this->n != v.n) throw "different dim";
		for (int i = 0; i < this->n; i++) this->vect[i] -= v.vect[i];
		return *this;
	}
	Vector operator-(const Vector& v) const {
		Vector c(this->n, this->vect);
		c -= v;
		return c;
	}

	Vector operator*=(double a) {
		for (int i = 0; i < n; i++) this->vect[i] *= a;
		return *this;
	}
	Vector operator*(double a)const {
		Vector c(this->n, this->vect);
		c *= a;
		return c;
	}

	Vector operator/=(double a) {
		*this = (*this) *(1/ a);
		return *this;
	}
	Vector operator/(double a)const {
		Vector c(this->n, this->vect);
		return c /a;
	}

	bool operator==(const Vector& v) const{
		if (this->n != v.n)return false;
		for (int i = 0; i < this->n; i++) if (this->vect[i] != v.vect[i])return false;
		return true;
	}
	bool operator!=(const Vector& v) {
		if (!(*this == v)) return true;
		else return false;
	}
	
	double& operator[](int ind) {
		if (ind < 0) throw "incorrect index";
		return this->vect[ind];
	}

	double operator[](int ind) const {
		if (ind < 0) throw "incorrect index";
		return this->vect[ind];
	}

	//methods
	double dot(const Vector& v) const {
		if (this->n != v.n) throw "different dim";
		double s = 0;
		for (int i = 0; i < n; i++) s += this->vect[i] * v.vect[i];
		return s;
	}

	double norm() const {
		return this->dot(*this);
	}

	double dist(const Vector & v) const {
		return (*this - v).norm();
	}

	//print
	void print() {
		std::cout << "(";
		for (int i = 0; i < this->n - 1; i++)std::cout << this->vect[i] << ", ";
		std::cout << this->vect[n - 1] << ")" << std::endl;
	}
};

