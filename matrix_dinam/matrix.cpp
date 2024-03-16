#include "matrix.h"

//constructor
matrix::matrix(int n, int m, double** M) {
	this->n = n;
	this->m = m;
	this->matr = new double* [n];
	for (int i = 0; i < n; i++) {
		this->matr[i] = new double[m];
		for (int j = 0; j < m; j++) {
			if(M == nullptr) this->matr[i][j] = 0;
			else this->matr[i][j] = M[i][j];
		}
	}
}

//copy constructor
matrix::matrix(const matrix& M):n(M.n), m(M.m)  {
	this->n = M.n;
	this->m = M.m;
	if (M.matr == nullptr) return;
	this->matr = new double* [n];
	for (int i = 0; i < n; i++) {
		this->matr[i] = new double[m];
		for (int j = 0; j < m; j++) {
			this->matr[i][j] = M.matr[i][j];
		}
	}
}
//operator=
matrix& matrix::operator=(const matrix& M) {
	if (this == &M) return *this;
	for (int i = 0; i < n; i++)delete[] this->matr[i];
	delete[] this->matr;
	this->n = M.n;
	this->m = M.m;
	this->matr = new double* [n];
	for (int i = 0; i < n; i++) {
		this->matr[i] = new double[m];
		for (int j = 0; j < m; j++) {
			this->matr[i][j] = M.matr[i][j];
		}
	}
	return *this;
}
//destructor
matrix::~matrix() {
	for (int i = 0; i < n; i++)delete[] this->matr[i];
	delete[] this->matr;
}

//operators
matrix& matrix::operator*=(double a) {
	if (this->matr == nullptr) throw "matrix does not exist";
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->m; j++)this->matr[i][j] *= a;
	}
	return *this;
}
matrix matrix::operator*(double a) const {
	matrix M = *this;
	M *= a;
	return M;
}

matrix& matrix::operator/=(double a) {
	if (a == 0 || a == -0) throw "division by zero is not possible";
	*this *= 1 / a;
	return *this;
}
matrix matrix::operator/(double a) const {
	matrix M = *this;
	M /= a;
	return M;
}

matrix matrix::operator-() const{
	matrix M = *this;
	M *= -1;
	return M;
}

matrix& matrix::operator+=(const matrix& M) {
	if (this->n != M.n || this->m != M.m) throw "different sizes";
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->m; j++)this->matr[i][j] += M.matr[i][j];
	}
	return *this;
}
matrix matrix::operator+(const matrix& M) const {
	matrix Ma = *this;
	Ma += M;
	return Ma;
}

matrix& matrix::operator-=(const matrix& M) {
	*this += -M;
	return *this;
}
matrix matrix::operator-(const matrix& M) const {
	matrix Ma = *this;
	Ma -= M;
	return Ma;
}

matrix& matrix::operator*=(const matrix& M) {
	*this = (*this) * M;
	return *this;
}
matrix matrix::operator*(const matrix& M) const {
	matrix New(this->n, M.m);
	if (this->m != M.n) throw "multiplication is not possible";
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < M.m; j++) {
			double sum = 0;
			for (int p = 0; p < this->m; p++) sum += this->matr[i][p] * M.matr[p][j];
			New.matr[i][j] = sum;
		}
	}
	return New;
}

double matrix::operator()(int i, int j) const {
	return this->matr[i][j];
}
double& matrix::operator()(int i, int j) {
	return this->matr[i][j];
}


//methods
matrix matrix::transposed() const {
	matrix M(this->m, this->n);
	for (int i = 0; i < M.n; i++) {
		for (int j = 0; j < M.m; j++) M.matr[i][j] = this->matr[j][i];
	}
	return M;
}
matrix& matrix::transpose() {
	(*this) = (*this).transposed();
	return *this;
}

matrix matrix::getAddition(int i, int j) const{
	matrix M(this->n -1, this->m -1);
	for (int p = 0; p < i; p++) {
		for (int q = 0; q < j; q++) M.matr[p][q] = this->matr[p][q];
		for (int q = j + 1; q < M.m + 1; q++) M.matr[p][q - 1] = this->matr[p][q];
	}
	for (int p = i + 1; p < M.n + 1; p++) {
		for (int q = 0; q < j; q++) M.matr[p-1][q] = this->matr[p][q];
		for (int q = j + 1; q < M.m + 1; q++) M.matr[p - 1][q - 1] = this->matr[p][q];
	}
	return M;
}

double matrix::det() const {
	if (this->n != this->m) throw "determinant does not exist";
	if (this->n == 1) return this->matr[0][0];
	double sum = 0;
	int sign = 1;
	for (int i = 0; i < this->n; i++) {
		sum += sign * (this->matr[0][i]) * (this->getAddition(0, i)).det();
		sign *= -1;
	}
	return sum;
}

matrix& matrix::init() {
	int p = 0, q = 0;
	std::cin >> p >> q;
	matrix M(p, q);
	for (int i = 0; i < M.n; i++) {
		for (int j = 0; j < M.m; j++) {
			std::cin >> M.matr[i][j];
		}
	}
	(*this) = M;
	return *this;
}

void matrix::print() {
	for (int i = 0; i < this->n; i++) {
		std::cout << std::endl;
		for (int j = 0; j < this->m; j++) std::cout << this->matr[i][j] << " ";
	}
	std::cout << std::endl;
}

