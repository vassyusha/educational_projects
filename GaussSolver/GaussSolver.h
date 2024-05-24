#pragma once
#include <vector>
#include "Matrix.h"

using Vector = VectorTemplate<double>;
class GaussSolver
{
private:
	void diag(Matrix& A);//приведение к диагональному виду
	std::vector<bool> basis(const Matrix& ext, int& r);
	std::vector<Vector> answer(const Matrix& A, int r, const std::vector<bool>& bas);//преобразование матрицы в ответ
	
public:
	std::vector<Vector> solve(const Matrix& A, const Vector& b);
};

