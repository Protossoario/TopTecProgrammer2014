/*
 * =====================================================================================
 *
 *       Filename:  COJ1197-MegaSearcher.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/17/14 19:03:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eduardo Alberto Sanchez Alvarado (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
#define pow2(X) pow(2, X);
int parseIP(string s) {
	int res = 0;
	int ind0 = 0;
	int ind1 = s.find('.');
	res = res | (atoi(s.substr(ind0, ind1).c_str())) << 24;
	ind0 = ind1 + 1;
	ind1 = s.find('.', ind0);
	res = res | (atoi(s.substr(ind0, ind1).c_str())) << 16;
	ind0 = ind1 + 1;
	ind1 = s.find('.', ind0);
	res = res | (atoi(s.substr(ind0, ind1).c_str())) << 8;
	res = res | (atoi(s.substr(ind1 + 1).c_str()));
	return res;
}
int range(int A, int B) {
	int shift = 24;
	int sum = 0;
	while (shift >= 0) {
		int Ai = (A >> shift) & 255;
		int Bi = (B >> shift) & 255;
		if (Ai != Bi) {
			sum += (Ai - Bi - 1) * pow2(shift);
			if (shift == 0) sum += 2;
			int shift2 = shift - 8;
			while (shift2 >= 0) {
				Ai = (A >> shift2) & 255;
				Bi = (B >> shift2) & 255;
				sum += (Ai - Bi + 255) * pow2(shift2);
				if (shift2 == 0) sum += 2;
				shift2 -= 8;
			}
			return sum;
		}
		shift -= 8;
	}
	return 1;
}
int main(int argc, const char *argv[])
{
	string A, B;
	cin >> A >> B;
	cout << range(parseIP(A), parseIP(B)) << endl;
	return 0;
}
