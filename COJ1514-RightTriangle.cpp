#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int N;
	double B, C;
	cout << fixed << setprecision(4);
	cin >> N;
	while (N--) {
		cin >> B >> C;
		double diagonal = (B * C) / sqrt(pow(B, 2) + pow(C,2));
		cout << (pow(diagonal, 2) / 2) << endl;
	}
}
