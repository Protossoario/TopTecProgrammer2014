#include <iostream>
#include <string>
using namespace std;

int sequence(string seq) {
	if (seq == "TTT") {
		return 0;
	}
	else if (seq == "TTH") {
		return 1;
	}
	else if (seq == "THT") {
		return 2;
	}
	else if (seq == "THH") {
		return 3;
	}
	else if (seq == "HTT") {
		return 4;
	}
	else if (seq == "HTH") {
		return 5;
	}
	else if (seq == "HHT") {
		return 6;
	}
	else if (seq == "HHH") {
		return 7;
	}
	return -1;
}

int main() {
	int arr[8], P, N;
	string s;
	cin >> P;
	while (P--) {
		cin >> N >> s;
		for (int i = 0; i < 8; i++) {
			arr[i] = 0;
		}
		for (unsigned int i = 0; i < s.length() - 2; i++) {
			arr[sequence(s.substr(i, 3))]++;
		}
		cout << N << " ";
		for (int i = 0; i < 7; i++) {
			cout << arr[i] << " ";
		}
		cout << arr[7] << endl;
	}
	return 0;
}
