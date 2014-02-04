#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, length;
	string str;
	cin >> N;
	while (N--) {
		cin >> str;
		length = (int) sqrt(str.length());
		for (int i = length - 1; i >= 0; i--) {
			for (unsigned int j = i; j < str.length(); j += length) {
				cout << str[j];
			}
		}
		cout << endl;
	}
}
