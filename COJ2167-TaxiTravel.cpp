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
		min = (taxis[1] < taxis[2] ? taxis[1] : taxis[2]);
		taxis[3] += min;
		taxis[1] -= min;
		taxis[2] -= min;
		min = (taxis[1] < taxis[3] ? taxis[1] : taxis[3]);
		S += min;
		taxis[3] -= min;
		taxis[1] -= min;
		for (int i = 1; i < 4; i++) {
			if (taxis[i] > 0) {
				S += taxis[i];
				taxis[i] = 0;
			}
		}
		cout << S << endl;
	}
}
