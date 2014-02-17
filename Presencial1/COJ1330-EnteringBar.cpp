#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, N, sum;
	string alcohols[11] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
	string s;
	cin >> T;
	while (T--) {
		cin >> N;
		sum = 0;
		while (N--) {
			cin >> s;
			if (isdigit(s[0])) {
				int age = atoi(s.c_str());
				if (age < 18) {
					sum++;
				}
			}
			else {
				for (int i = 0; i < 11; i++) {
					if (s == alcohols[i]) {
						sum++;
						break;
					}
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
