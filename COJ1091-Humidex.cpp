/*
 * =====================================================================================
 *
 *       Filename:  COJ1091-Humidex.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/11/14 20:28:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eduardo Alberto Sanchez Alvarado (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
double humidex(double T, double D) {
	return T + (0.5555) * (6.11 * exp(5417.753 * ((1 / 273.16) - (1 / (D + 273.16)))) - 10);
}
double dew(double T, double H) {
	return 5417.753 * (1 / ((5417.753 / 273.16) - log((H + T) / 3.39411))) - 273.16;
}
int main(int argc, const char *argv[])
{
	char c1, c2;
	double in1, in2, out;
	cout << fixed << setprecision(1);
	while (cin >> c1 && c1 != 'E') {
		cin >> in1 >> c2 >> in2;
		if (c2 == 'D') {
			out = humidex(in1, in2);
			cout << "T " << in1 << " D " << in2 << " H " << out << endl;
		}
		else {
			out = dew(in1, in2);
			cout << "T " << in1 << " D " << out << " H " << in2 << endl;
		}
	}
	return 0;
}
