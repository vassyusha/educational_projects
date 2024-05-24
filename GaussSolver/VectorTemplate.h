#pragma once
#include <iostream>

template <class T>
class VectorTemplate
{
private:
	int n = 0;
	T* data = nullptr;
public:
	//usual constructor
	VectorTemplate(int dim = 0, T el = 0) {
		if (dim == 0) return;
		this->n = dim;
		this->data = new T[this->n];
		for (int i = 0; i < n; i++) this->data[i] = el;
	}

	//copy constructor
	VectorTemplate(const VectorTemplate& v) :n(v.n) {
		this->data = new T[this->n];
		for (int i = 0; i < this->n; i++)this->data[i] = v.data[i];
	}

	//operator =
	VectorTemplate& operator=(const VectorTemplate& v) {
		if (this == &v) return *this;
		this->n = v.n;
		delete[] this->data;
		this->data = new T[this->n];
		for (int i = 0; i < this->n; i++)this->data[i] = v.data[i];
		return *this;
	}

	//destructor
	~VectorTemplate() {
		//std::cout << "dest\n";
		/*for (int i = 0; i < this->n; i++);
		std::cout << "\n";*/
		delete[] this->data;
	}

	//operators
	VectorTemplate operator-() const {
		VectorTemplate c(this->n);
		for (int i = 0; i < this->n; i++)c.data[i] = -(this->data[i]);
		return c;
	}

	VectorTemplate& operator+=(const VectorTemplate& v) {
		if (this->n != v.n) throw "different dim";
		for (int i = 0; i < this->n; i++) this->data[i] += v.data[i];
		return *this;
	}
	VectorTemplate operator+(const VectorTemplate& v) const {
		VectorTemplate c(*this);
		c += v;
		return c;
	}

	VectorTemplate& operator-=(const VectorTemplate& v) {
		if (this->n != v.n) throw "different dim";
		for (int i = 0; i < this->n; i++) this->data[i] -= v.data[i];
		return *this;
	}
	VectorTemplate operator-(const VectorTemplate& v) const {
		VectorTemplate c(*this);
		c -= v;
		return c;
	}

	VectorTemplate& operator*=(double a) {
		for (int i = 0; i < n; i++) this->data[i] *= a;
		return *this;
	}
	VectorTemplate operator*(double a)const {
		VectorTemplate c(*this);
		c *= a;
		return c;
	}

	VectorTemplate& operator/=(double a) {
		*this = (*this) * (1 / a);
		return *this;
	}
	VectorTemplate operator/(double a)const {
		VectorTemplate c(*this);
		return c /= a;
	}

	bool operator==(const VectorTemplate& v) const {
		if (this->n != v.n)return false;
		for (int i = 0; i < this->n; i++) if (this->data[i] != v.data[i])return false;
		return true;
	}
	bool operator!=(const VectorTemplate& v) {
		if (!(*this == v)) return true;
		else return false;
	}

	T& operator[](int ind) {
		if (ind < 0) throw "incorrect index";
		return this->data[ind];
	}

	T operator[](int ind) const {
		if (ind < 0) throw "incorrect index";
		return this->data[ind];
	}

	int size() { return n; }

	friend std::ostream& operator << (std::ostream& ostr, const VectorTemplate& a) {
		ostr << "(";
		for (int i = 0; i < a.n - 1; i++) ostr << a.data[i] << ", ";
		ostr << a.data[a.n - 1] << ")";
		return ostr;
	}

	friend std::istream& operator >> (std::istream& istr, VectorTemplate& a) {
		for (int i = 0; i < a.n; i++) istr >> a[i];
		return istr;
	}
};