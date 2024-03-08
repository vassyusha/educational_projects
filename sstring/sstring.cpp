#include "sstring.h"

//constructors
sstring::sstring() {
	this->n = 1;
	this->str = new char[this->n];
	this->str[0] = '\0';
}
sstring::sstring(const char* s) {
	int i = 0;
	while (s[i] != '\0')i++;
	this->n = i+1;
	this->str = new char[this->n];
	for (int i = 0; i < this->n; i++) {
		this->str[i] = s[i];
	}
}
sstring::sstring(const char& c) {
	this->n = 2;
	this->str = new char[this->n];
	str[0] = c;
	str[1] = '\0';
}

//Tree
sstring::sstring(const sstring& s) : n(s.n) { //copy constructor
	this->str = new char[this->n];
	for (int i = 0; i < this->n; i++) this->str[i] = s.str[i];
}
sstring& sstring::operator=(const sstring& s) {//operator=
	if (this->str == s.str) return *this;
	this->n = s.n;
	delete[] this->str;
	this->str = new char[this->n];
	for (int i = 0; i < this->n; i++) this->str[i] = s.str[i];
	return *this;
}
sstring& sstring::operator=(const char* s) {
	*this = sstring(s);
	return *this;
}
sstring::~sstring() {//destructor
	delete[] this->str;
}

//operators
char& sstring::operator[](int ind) {
	if (ind > this->n - 1) throw "incorrect index";
	return this->str[ind];
}
char sstring::operator[](int ind) const {
	if (ind > this->n - 1) throw "incorrect index";
	return this->str[ind];
}

sstring& sstring::operator+=(const sstring& s) {
	sstring temp = *this;
	this->n += s.n - 1;
	delete[] this->str;
	this->str = new char[this->n];
	for (int i = 0; i < this->n - s.n; i++) (*this)[i] = temp[i];
	for (int i = this->n - s.n; i < this->n; i++) {
		(*this)[i] = s[i - this->n + s.n];
	}
	return *this;
}
sstring sstring::operator+(const sstring& s) const {
	sstring str = *this;
	str += s;
	return str;
}

sstring& sstring::operator+=(const char& c) {
	*this += sstring(c);
	return *this;
}
sstring sstring::operator+(const char& c) const {
	sstring str = *this;
	str += c;
	return str;
}

bool sstring::operator==(const sstring& s) const {
	if (this->n != s.n) return false;
	for (int i = 0; i < this->n; i++) if (this->str[i] != s[i]) return false;
	return true;
}
bool sstring::operator!=(const sstring& s)const {
	if (!(*this == s)) return true;
	return false;
}

bool sstring::operator>(const sstring& s)const {
	for (int i = 0; i < this->n && i < s.n; i++) if (this->str[i] > s[i]) return true;
	if (this->n > s.n) return true;
	return false;
}
bool sstring::operator<(const sstring& s)const {
	for (int i = 0; i < this->n && i < s.n; i++) if (this->str[i] < s[i]) return true;
	if (this->n < s.n) return true;
	return false;
}

bool sstring::operator>=(const sstring& s)const {
	if (*this > s || *this == s) return true;
	return false;
}
bool sstring::operator<=(const sstring& s)const {
	if (*this < s || *this == s) return true;
	return false;
}

//methods
int sstring::size() const {return this->n - 1;}
sstring& sstring::clear() {
	this->n = 1;
	delete[] this->str;
	this->str = new char[this->n];
	this->str[0] = '\0';
	return *this;
}
bool sstring::empty() const {
	if (this->n == 1) return true;
	return false;
}

sstring sstring::substr(int start, int end) const{
	sstring s;
	s.n = end - start + 1;
	s.str = new char[s.n];
	for (int i = 0; i < s.n - 1; i++) {
		s[i] = (*this)[start + i];
	}
	s[s.n - 1] = '\0';
	return s;
}

sstring sstring::insert(int pos, const sstring& s) const{
	sstring temp;
	sstring first = this->substr(0, pos);
	sstring second = this->substr(pos, this->n);
	temp = first + s + second;
	return temp;
}
sstring sstring::insert(int pos, const char* s) const {
	sstring temp = this->insert(pos, sstring(s));
	return temp;
}
sstring sstring::insert(int pos, const char& c) const{
	sstring temp = this->insert(pos, sstring(c));
	return temp;
}

sstring sstring::erase(int pos) const{
	sstring temp = this->substr(0, pos) + this->substr(pos + 1, this->n);
	return temp;
}
sstring sstring::erase(int pos, int count) const {
	sstring temp = this->substr(0, pos) + this->substr(pos + count, this->n);
	return temp;
}

int sstring::find(const sstring& s) {
	int count = 0;
	int i = 0;
	for (; i < this->n && count < s.size(); i++) {
		if ((*this)[i] == s[count]) count++;
	}
	if (count == s.size()) return (i - count + 1);
	return -1;
}

void sstring::printl() const{
	std::cout << this->str << std::endl;
}
void sstring::print() const {
	std::cout << this->str << " ";
}
