#pragma once
#include <iostream>

class matrix
{
private:
	int n = 0, m = 0;
	double** matr = nullptr;

	matrix getAddition(int i, int j) const;//tested
public:
	//constructors
	matrix(int n = 1, int m = 1, double** mat = nullptr);//tested

	//copy constructor
	matrix(const matrix& M);//hasn't been tested, but work
	//operator=
	matrix& operator=(const matrix& M);//tested
	//destructor
	~matrix();

	//operators
	matrix& operator*=(double a);//tested
	matrix operator*(double a) const;//tested

	matrix& operator/=(double a);//tested
	matrix operator/(double a) const;//tested

	matrix operator-() const;//tested

	matrix& operator+=(const matrix& M);//tested
	matrix operator+(const matrix& M) const;//tested

	matrix& operator-=(const matrix& M);//tested
	matrix operator-(const matrix& M) const;//tested

	matrix& operator*=(const matrix& M);//tested
	matrix operator*(const matrix& M) const;//tested

	double operator()(int i, int j) const;
	double& operator()(int i, int j);

	//methods
	matrix& transpose();//tested
	matrix transposed() const;//tested

	

	double det() const; //tested

	matrix& init();//tested
	void print();//tested

};

