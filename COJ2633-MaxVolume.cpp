#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.14159
double coneVolume(const double &R, const double &H) {
	return PI * pow(R, 2) * H / 3;
}
double cylinderVolume(const double &R, const double &H) {
	return PI * pow(R, 2) * H;
}
double sphereVolume(const double &R) {
	return PI * pow(R, 3) * 4 / 3;
}
int main(int argc, const char *argv[])
{
	int N;
	char c;
	double R, H, vol, max = 0;
	cin >> N;
	while (N--) {
		cin >> c;
		switch (c) {
			case 'C':
				cin >> R >> H;
				vol = coneVolume(R, H);
				break;
			case 'L':
				cin >> R >> H;
				vol = cylinderVolume(R, H);
				break;
			case 'S':
				cin >> R;
				vol = sphereVolume(R);
				break;
		}
		if (vol > max) {
			max = vol;
		}
	}
	cout << fixed << setprecision(3) << max << endl;
	return 0;
}
