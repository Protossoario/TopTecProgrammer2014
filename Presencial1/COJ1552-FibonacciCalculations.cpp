#include <iostream>
using namespace std;

int main () {
	int fib0, fib1, fN, fM, T, N, M;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		fib0 = 0;
		fib1 = 1;
		fN = 1;
		int i;
		for (i = 2; i < N; i++) {
			int aux = fib1;
			fib1 = fib0 + fib1;
			fib0 = aux;
			fN  = fN + fib1;
		}
		fM = fN;
		for (; i <= M; i++) {
			int aux = fib1;
			fib1 =  fib0 + fib1;
			fib0 = aux;
			fM = fM + fib1;
		}
		fN = (N == 0 || N == 1 ? 0 : fN);
		fM = (M == 0 ? 0 : (M == 1 ? 1 : fM));
		cout << fM - fN << endl;
	}
}
