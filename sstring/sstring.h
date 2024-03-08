#pragma once
#include <iostream>

class sstring
{
private:
	int n = 0;
	char* str = nullptr;
public:
	//constructors
	sstring();
	sstring(const char*);
	sstring(const char&);

	//Three
	sstring(const sstring&);//copy constructor
	sstring& operator=(const sstring&);//operator =
	sstring& operator=(const char*);
	sstring& operator=(const char&);
	~sstring();//destructor

	//operators
	char& operator[](int);
	char operator[](int) const;

	sstring& operator+=(const sstring&);
	sstring operator+(const sstring&) const;

//	sstring& operator+=(const char&);
//	sstring operator+(const char&) const;

	bool operator==(const sstring&) const;
	bool operator!=(const sstring&)const;

	bool operator>(const sstring&)const;
	bool operator<(const sstring&)const;
	bool operator>=(const sstring&)const;
	bool operator<=(const sstring&)const;

	//methods
	int size() const;
	sstring& clear();
	bool empty() const;

	sstring substr(int, int) const;

	sstring insert(int, const sstring&) const;
	//sstring insert(int, const char*) const;
	//sstring insert(int, const char&) const;
	
	
	sstring erase(int, int=1) const;

	int find(const sstring&);

	//print
	void printl() const;
	void print() const;
};

