#pragma once
#include <vector>
#include "Matrix.h"

using Vector = VectorTemplate<double>;
class GaussSolver
{
private:
	void diag(Matrix& A);//���������� � ������������� ����
	std::vector<bool> basis(const Matrix& ext, int& r);
	std::vector<Vector> answer(const Matrix& A, int r, const std::vector<bool>& bas);//�������������� ������� � �����
	
public:
	std::vector<Vector> solve(const Matrix& A, const Vector& b);
};

