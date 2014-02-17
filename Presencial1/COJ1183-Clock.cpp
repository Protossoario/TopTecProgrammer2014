#include <iostream>
using namespace std;

bool compatible(bool num[5][3], bool disp[5][3]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (disp[i][j] && !num[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool num0[5][3] =
{
	{1,1,1},
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,1,1}
};
bool num1[5][3] =
{
	{0,0,1},
	{0,0,1},
	{0,0,1},
	{0,0,1},
	{0,0,1}
};
bool num2[5][3] =
{
	{1,1,1},
	{0,0,1},
	{1,1,1},
	{1,0,0},
	{1,1,1}
};
bool num3[5][3] =
{
	{1,1,1},
	{0,0,1},
	{1,1,1},
	{0,0,1},
	{1,1,1}
};
bool num4[5][3] =
{
	{1,0,1},
	{1,0,1},
	{1,1,1},
	{0,0,1},
	{0,0,1}
};
bool num5[5][3] =
{
	{1,1,1},
	{1,0,0},
	{1,1,1},
	{0,0,1},
	{1,1,1}
};
bool num6[5][3] =
{
	{1,1,1},
	{1,0,0},
	{1,1,1},
	{1,0,1},
	{1,1,1}
};
bool num7[5][3] =
{
	{1,1,1},
	{0,0,1},
	{0,0,1},
	{0,0,1},
	{0,0,1}
};
bool num8[5][3] =
{
	{1,1,1},
	{1,0,1},
	{1,1,1},
	{1,0,1},
	{1,1,1}
};
bool num9[5][3] =
{
	{1,1,1},
	{1,0,1},
	{1,1,1},
	{0,0,1},
	{1,1,1}
};

int minCompatible(bool disp[5][3]) {
	if (compatible(num0, disp)) {
		return 0;
	}
	else if (compatible(num1, disp)) {
		return 1;
	}
	else if (compatible(num2, disp)) {
		return 2;
	}
	else if (compatible(num3, disp)) {
		return 3;
	}
	else if (compatible(num4, disp)) {
		return 4;
	}
	else if (compatible(num5, disp)) {
		return 5;
	}
	else if (compatible(num6, disp)) {
		return 6;
	}
	else if (compatible(num7, disp)) {
		return 7;
	}
	else if (compatible(num8, disp)) {
		return 8;
	}
	return 9;
}

int main() {
		bool h1[5][3], h2[5][3], m1[5][3], m2[5][3];
	int N;
	cin >> N;
	while (N--) {
		string s;
		for (int i = 0; i < 5; i++) {
			cin >> s;
			for (int k = 0; k < 3; k++) {
				h1[i][k] = (s[k] == '#');
			}
			cin >> s;
			for (int k = 0; k < 3; k++) {
				h2[i][k] = (s[k] == '#');
			}
			cin >> s;
			for (int k = 0; k < 3; k++) {
				m1[i][k] = (s[k] == '#');
			}
			cin >> s;
			for (int k = 0; k < 3; k++) {
				m2[i][k] = (s[k] == '#');
			}
		}
		int h1min = minCompatible(h1);
		int h2min = minCompatible(h2);
		int m1min = minCompatible(m1);
		int m2min = minCompatible(m2);
		cout << h1min << h2min << ":" << m1min << m2min << endl;
	}
	return 0;
}
