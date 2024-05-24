
#include <vector>
#include "GaussSolver.h"


int main() {

	GaussSolver s;
	Matrix A(2, 5);
	Vector b(2);

	std::cin >> A;
	std::cin >> b;

	std::vector<Vector> ans = s.solve(A, b);
	for (int i = 0; i < ans.size(); i++)std::cout << ans[i];
}
