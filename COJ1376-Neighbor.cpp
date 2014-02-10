#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string num;
	while (cin >> num) {
		if (next_permutation(num.begin(), num.end())) {
			cout << num << endl;
		}
		else {
			cout << "0" << endl;
		}
	}
	return 0;
}
