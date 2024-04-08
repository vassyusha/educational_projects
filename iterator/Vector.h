#pragma once
#include <iostream>


class Vector
{
private:
	int n = 0;
	int capacity = 0;
	double* array = nullptr;

public:
	//constructor
	Vector(int n = 0, double* data = nullptr);

	//copy constructor
	Vector(const Vector& v);
	//operator=
	Vector& operator=(const Vector& v);
	//destructor
	~Vector();

	//operators
	double operator[](int index) const;
	double& operator[](int index);

	//extra class
	class iterator {
	private:
		double* it = nullptr;
		Vector* arr = nullptr;
		
	public:
		iterator(double* elem, Vector* arr);

		double& operator*();
		double operator*() const;

		iterator& operator++();
		iterator operator++(int);//postfix

		bool operator!=(iterator iter) const;
		bool operator==(iterator iter) const;
		bool operator>(iterator iter) const;
		bool operator<(iterator iter) const;
		bool operator>=(iterator iter) const;
		bool operator<=(iterator iter) const;

		iterator& operator--();
		iterator operator--(int);

		iterator& operator+=(int n);
		iterator& operator-=(int n);
		iterator operator+(int n) const;
		iterator operator-(int n) const;

		int operator-(iterator iter)const;

		void print();

	};

	//methods
	double size() const;
	bool empty() const;

	Vector& push_back(double next);
	Vector& pop_back();

	Vector& insert(int pos, const Vector& v);
	Vector& insert(int pos, int size, double* extra);

	Vector& erase(int pos, int num);

	void swap(int i, int j);

	void print();

	iterator begin();
	iterator end();

	
};
