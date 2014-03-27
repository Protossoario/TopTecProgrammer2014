/*
 * =====================================================================================
 *
 *       Filename:  COJ1369-InscribedTriangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2014 11:06:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eduardo Alberto Sanchez Alvarado (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <cmath>
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
	double L, Lpow2, N, K;
	const double a = sqrt(3.0) / 4.0;
	cin >> L >> N >> K;
	while (L != 0 || N != 0 || K != 0) {
		Lpow2 = pow(L,2);
		cout << (int) (a * Lpow2 - 3 * a * (Lpow2 * (K / N) * ((N - K) / N)) + 0.5) << endl;
		cin >> L >> N >> K;
	}
	return 0;
}
