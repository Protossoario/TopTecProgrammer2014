#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string toBinary(int n) {
	string res;
	do {
		res.push_back('0' + (n & 1));
	} while (n >>= 1);
	while (res.length() < 5) {
		res.push_back('0');
	}
	reverse(res.begin(), res.end());
	return res;
}
string convert(string str) {
	string res;
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			res += "00000";
		}
		else {
			res += toBinary(str[i] - 'A' + 1);
		}
	}
	return res;
}
char mat[20][20];
void fillMat(const string &s, const int &R, const int &C) {
	int str_ind, i, k, l, m , n;
	str_ind = i = k = l = 0;
	m = R;
	n = C;
	while (k < m && l < n) {
		for (i = l; i < n; i++) {
			mat[k][i] = (str_ind < (int) s.length() ? s[str_ind++] : '0');
		}
		k++;
		n--;
		for (i = k; i < m; i++) {
			mat[i][n] = (str_ind < (int) s.length() ? s[str_ind++] : '0');
		}
		if (k < m) {
			m--;
			for (i = n - 1; i >= l; i--) {
				mat[m][i] = (str_ind < (int) s.length() ? s[str_ind++] : '0');
			}
		}
		if (l < n) {
			for (i = m - 1; i >= k; i--) {
				mat[i][l] = (str_ind < (int) s.length() ? s[str_ind++] : '0');
			}
			l++;
		}
	}
}
int main(int argc, const char *argv[])
{
	int N, R, C;
	string str;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> R >> C;
		cin.ignore(1, ' ');
		getline(cin, str);
		str = convert(str);
		fillMat(str, R, C);
		cout << i << " ";
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cout << mat[j][k];
			}
		}
		cout << endl;
	}
	return 0;
}
