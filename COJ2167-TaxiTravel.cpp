#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main() {
	int T, N, S, s;
	int taxis[4] = {0, 0, 0, 0};
	cin >> T;
	while (T--) {
		cin >> N;
		S = 0;
		while (N--) {
			cin >> s;
			if (s != 4) {
				taxis[s]++;
			}
			else {
				S++;
			}
		}
		int min = (taxis[1] < taxis[3] ? taxis[1] : taxis[3]);
		S += min;
		taxis[3] -= min;
		taxis[1] -= min;
		S += taxis[2] / 2;
		taxis[2] = taxis[2] % 2;
		if (taxis[2] > 0) {
			if (taxis[1] > 1) {
				taxis[1] -= 2;
				taxis[2]--;
				S++;
			}
			else if (taxis[1] > 0) {
				taxis[1]--;
				taxis[2]--;
				S++;
			}
		}
		S += taxis[1] / 4;
		taxis[1] = taxis[1] % 4;
		for (int i = 1; i < 4; i++) {
			if (taxis[i] > 0) {
				S += taxis[i];
				taxis[i] = 0;
			}
		}
		cout << S << endl;
	}
}
