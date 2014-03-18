#include <climits>
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
	int N, num, max = 0, max_num;
	cin >> N;
	while (N--) {
		int factor = 0;
		cin >> num;
		int aux = num;
		for (int i = 2; i <= aux / i; i++) {
			if (aux % i == 0) {
				factor = i;
				do {
					aux /= i;
				} while (aux % i == 0);
			}
		}
		if (aux != 1) {
			factor = aux;
		}
		if (factor > max) {
			max = factor;
			max_num = num;
		}
	}
	cout << max_num << endl;
	return 0;
}

