#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, N, S, s;
	cin >> T;
	while (T--) {
		cin >> N;
		S = 0;
		while (N--) {
			cin >> s;
			S += s;
		}
		cout << ((S / 4) + (S % 4 == 0 ? 0 : 1)) << endl;
	}
}
