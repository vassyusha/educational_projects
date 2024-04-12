#include "Vector.h"

Vector::Vector(int n, double* data) {
	if (n < 0) throw "incorrect size";
	if (n == 0) {
		capacity = 1;
	}
	else {
		this->n = n;
		this->capacity = n * 2;
	}
	this->array = new double[capacity];

	for (int i = 0; i < this->n; i++) {
		if (data == nullptr) this->array[i] = 0;
		else this->array[i] = data[i];
	}
}

Vector::Vector(const Vector& v) {
	if (v.n == 0) return;
	this->n = v.n;
	this->capacity = this->n * 2;
	this->array = new double[capacity];
	for (int i = 0; i < n; i++)this->array[i] = v.array[i];
}
Vector& Vector::operator=(const Vector& v) {
	if (this == &v) return *this;
	this->n = v.n;
	if (this->n <= this->capacity) {
		for (int i = 0; i < n; i++) this->array[i] = v.array[i];
	}
	else {
		delete[] this->array;
		this->capacity = this->n * 2;
		this->array = new double[capacity];
		for (int i = 0; i < n; i++)this->array[i] = v.array[i];
	}
	return *this;
}
Vector::~Vector() {
	delete[] this->array;
}

double Vector::operator[](int index) const {
	if (index < 0 || index >= this->n) throw "incorrect index";
	return this->array[index];
}
double& Vector::operator[](int index) {
	if (index < 0 || index >= this->n) throw "incorrect index";
	return this->array[index];
}

double Vector::size() const {
	return this->n;
}

bool Vector::empty() const {
	if (this->n == 0) return true;
	return false;
}

Vector& Vector::push_back(double next) {
	if (this->n + 1 > this->capacity) {
		this->n++;
		this->capacity = this->n * 2;
		double* temp = new double[capacity];
		for (int i = 0; i < this->n - 1; i++)temp[i] = this->array[i];
		delete[] this->array;
		this->array = temp;
	}
	this->n++;
	array[this->n - 1] = next;
	return *this;
}

Vector& Vector::pop_back() {
	this->n--;//ïîäóìàòü íàä óäàëåíèåì ïàìÿòè
	return *this;
}

Vector& Vector::insert(int pos, const Vector& v) {

	if (pos < 0 || pos > this->n) throw"incorrect index";

	this->capacity = (this->n + v.n) * 2;
	double* temp = new double[capacity];

	for (int i = 0; i < pos; i++) temp[i] = this->array[i];
	for (int i = pos; i < pos + v.n; i++) temp[i] = v.array[i - pos];
	for (int i = pos + v.n; i < this->n + v.n; i++) temp[i] = this->array[i - v.n];

	this->n += v.n;
	delete[] this->array;
	this->array = temp;
	
	return *this;
}
Vector& Vector::insert(int pos, int size, double* extra) {
	
	this->insert(pos, Vector(size, extra));
	return *this;
}

Vector& Vector::erase(int pos, int num) {

	if (pos < 0 || pos + num > this->n) throw"incorrect index";

	for (int i = pos; i < this->n - num; i++)this->array[i] = this->array[i + num];
	this->n -= num;
	return *this;
}

void Vector::swap(int i, int j) {
	if (i < 0 || i >= this->n || j < 0 || j >= this->n) throw "incorrect index";
	if (i == j) return;
	double temp = this->array[i];
	this->array[i] = this->array[j];
	this->array[j] = temp;
}

/*void Vector::print() const {
	std::cout << "[";
	for (int i = 0; i < this->n - 1; i++)std::cout << this->array[i] << ", ";
	if(this->n - 1 >= 0) std::cout << this->array[this->n - 1] << "]" << std::endl;
	else std::cout << "]" << std::endl;
}*/

void Vector::print(){
	std::cout << "[";
	for (Vector::iterator i = this->begin(); i < this->end(); i++)std::cout << (*i) << ", ";
	if (!(this->empty())) std::cout << *(this->end() - 1);
	std::cout << "]" << std::endl;
}

Vector::iterator Vector::begin(){
	Vector::iterator it(this->array, this);
	return it;
}

Vector::iterator Vector::end(){
	Vector::iterator it = this->begin()+this->n;
	return it;
}

//iterator
Vector::iterator::iterator(double* elem, Vector* arr) {
	this->it = elem;
	this->arr = arr;
}

double& Vector::iterator::operator*() {
	if ((*this) < this->arr->begin() || (*this) >= this->arr->end()) throw "be more careful with memory, please";
	return *(this->it);
}

double Vector::iterator::operator*() const {
	if ((*this) < this->arr->begin() || (*this) >= this->arr->end()) throw "be more careful with memory, please";
	return *(this->it);
}

Vector::iterator& Vector::iterator::operator++() {
	this->it++;
	return *this;
}
Vector::iterator Vector::iterator::operator++(int) {
	iterator i = *this;
	++(*this);
	return i;
}

bool Vector::iterator::operator!=(Vector::iterator iter) const{
	if (this->it != iter.it)return true;
	return false;
}
bool Vector::iterator::operator==(Vector::iterator iter) const {
	return !((*this) != iter);
}
bool Vector::iterator::operator>(Vector::iterator iter) const {
	if (this->it > iter.it)return true;
	return false;
}
bool Vector::iterator::operator<(Vector::iterator iter) const {
	if (this->it < iter.it)return true;
	return false;
}
bool Vector::iterator::operator>=(Vector::iterator iter) const {
	return !((*this) < iter);
}
bool Vector::iterator::operator<=(Vector::iterator iter) const {
	return !((*this) > iter);
}

Vector::iterator& Vector::iterator::operator--() {
	this->it--;
	return *this;
}
Vector::iterator Vector::iterator::operator--(int) {
	iterator i = *this;
	--(*this);
	return i;
}

Vector::iterator& Vector::iterator::operator+=(int n) {
	this->it += n;
	return *this;
}
Vector::iterator Vector::iterator::operator+(int n) const{
	iterator i(this->it + n, this->arr);
	return i;
}

Vector::iterator& Vector::iterator::operator-=(int n) {
	this->it -= n;
	return *this;
}
Vector::iterator Vector::iterator::operator-(int n) const {
	iterator i(this->it - n, this->arr);
	return i;
}

int Vector::iterator::operator-(iterator iter)const {
	if ((*this) >= iter) return (this->it - iter.it);
	return (iter.it - this->it);
}

void Vector::iterator::print() {
	std::cout << this->it << std::endl;
}
