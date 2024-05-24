#include "GaussSolver.h"


std::vector<Vector> GaussSolver::solve(const Matrix& A, const Vector& b) {

	Matrix ext(A.getn(), A.getm() + 1);
	for (int i = 0; i < ext.getn(); i++) {
		for (int j = 0; j < ext.getm() - 1; j++) ext(i, j) = A(i, j);
		ext(i, ext.getm() - 1) = -b[i];
	}
	this->diag(ext);

	int r = 0;

	std::vector<bool> bas = this->basis(ext, r);
	
	return this->answer(ext, r, bas);

}

void swap(Vector& a, Vector& b){
	Vector tmp = a;
	a = b;
	b = tmp;
}

std::vector<bool> GaussSolver::basis(const Matrix& ext, int& r) {
	std::vector<bool> bas(ext.getm(), false);
	int i = 0, j = 0;

	for (; i < ext.getn();) {
		for (; j < ext.getm() - 1; j++) {
			while (ext(i, j) != 1 && j < ext.getm() - 1) j++;
			if (ext(i, j) == 1) {
				bas[j] = true;
				r++;
				j++;
				i++;
			}break;
		}if (j == ext.getm() - 1) break;
	}
	for (; i < ext.getn(); i++) {
		if (ext(i, j) != 0) {
			r = ext.getm();
			break;
		}
	}

	return bas;
}

void GaussSolver::diag(Matrix& A) {
	int n = A.getn(), m = A.getm();
	for (int i = 0, j = 0; i < n; i++) {//i - индекс по строкам, то есть в какой строке сейчас ведущий элемент
		for (; j < m-1; j++) {
			int g = i + 1;
			while (A(i, j) == 0 && g < n) {//j - соответственно ведущий элемент
				swap(A[i], A[g]);
				g++;
			}
			if (A(i, j) != 0) {
				A[i] /= A(i, j);
				for (int k = 0; k < n; k++) {
					if (k == i) continue;
					A[k] -= A[i] * A(k, j);
				}j++;
				break;
			}
		}
	}

}

std::vector<Vector> GaussSolver::answer(const Matrix& A, int r, const std::vector<bool>& bas) {
	int m = A.getm();
	std::vector<Vector> ans(m - r, Vector(m - 1));
	if (r == m) return ans;
	for (int i = 0, j = 0; i < ans.size(); i++) {// i - вектор ответа, который мы заполняем
		for (; j < bas.size(); j++) { //j - то, какой переменной этот вектор соответствует
			if (bas[j]) continue;
			int k = 0; //k - та строка, из которой пишем значение
			for (int p = 0; p < bas.size()-1; p++) {
				if (bas[p]) {
					ans[i][p] = -A(k, j);
					k++;
				}
				if (bas[p] == false && p == j) {
					ans[i][p] = 1;
				}
			}j++;
			break;//поcле того, как мы нашли нужный нам небазисный элемент, по которому мы будем задавать вектор нам надо перейти к заполнению следующего вектора
		}
	}

	if (ans.size() > 1) swap(ans[0], ans[ans.size() - 1]);

	return ans;
}


