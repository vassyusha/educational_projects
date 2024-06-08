#include "GaussSolver.h"
#define EPS 10e-11

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
			if (ext(i, j) == 1 && j != ext.getm()-1) {
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
	for (int i = 0, j = 0; i < n; i++) {//i - èíäåêñ ïî ñòðîêàì, òî åñòü â êàêîé ñòðîêå ñåé÷àñ âåäóùèé ýëåìåíò
		for (; j < m-1; j++) {
			int g = i + 1;
			while (g < n) {//j - ñîîòâåòñòâåííî âåäóùèé ýëåìåíò
				if(abs(A(i,j)) < abs(A(g,j))) swap(A[i], A[g]);
				g++;
			}
			if (A(i, j) != 0) {
				double el = A(i, j);
				for (int p = 0; p < m; p++) A(i, p) /= el;
				for (int k = 0; k < n; k++) {
					if (k == i) continue;
					el = A(k, j);
					for (int p = 0; p < m; p++){
						A(k, p) -= A(i, p) * el;
						if (abs(A(k, p)) < EPS) A(k, p) = 0;
					}
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
	for (int i = 0, j = 0; i < ans.size(); i++) {// i - âåêòîð îòâåòà, êîòîðûé ìû çàïîëíÿåì
		for (; j < bas.size(); j++) { //j - òî, êàêîé ïåðåìåííîé ýòîò âåêòîð ñîîòâåòñòâóåò
			if (bas[j]) continue;
			int k = 0; //k - òà ñòðîêà, èç êîòîðîé ïèøåì çíà÷åíèå
			for (int p = 0; p < bas.size()-1; p++) {
				if (bas[p]) {
					ans[i][p] = -A(k, j);
					k++;
				}
				if (bas[p] == false && p == j) {
					ans[i][p] = 1;
				}
			}j++;
			break;//ïîcëå òîãî, êàê ìû íàøëè íóæíûé íàì íåáàçèñíûé ýëåìåíò, ïî êîòîðîìó ìû áóäåì çàäàâàòü âåêòîð íàì íàäî ïåðåéòè ê çàïîëíåíèþ ñëåäóþùåãî âåêòîðà
		}
	}

	if (ans.size() > 1) swap(ans[0], ans[ans.size() - 1]);

	return ans;
}


