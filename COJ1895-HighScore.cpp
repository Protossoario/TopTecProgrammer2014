/*
 * =====================================================================================
 *
 *       Filename:  COJ1895-HighScore.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/23/14 12:22:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eduardo Alberto Sanchez Alvarado (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <climits>
using namespace std;
int min(const int &a, const int &b) {
	return a < b ? a : b;
}
int minOffset(const char &c) {
	return min(c - 'A', 'Z' - c + 1);
}
int main(int argc, const char *argv[])
{
	string s;
	int N, sum, ind1, min, min_ind1, min_ind2;
	bool A;
	cin >> N;
	while (N--) {
		cin >> s;
		min = INT_MAX;
		sum = 0;
		ind1 =  min_ind1 = min_ind2 = -1;
		A = false;
		for (unsigned int i = 0; i < s.length(); i++) {
			if (s[i] != 'A') {
				sum += minOffset(s[i]);
				if (A) {
					A = false;
					int dist = i - ind1;
					if (dist < min) {
						min = dist;
						min_ind1 = ind1;
						min_ind2 = i;
					}
				}
			}
			else if (!A) {
				ind1 = i;
				A = true;
			}
		}
		if (A) {
			ind2 = s.length();
		}
		if (min_ind1 == -1) {
			sum += s.length() - 1;
		}
		else if (min_ind1 == 0) {
			sum += s.length() - min;
		}
		else if (min_ind2 == s.length()) {
			sum += s.length() - min - 1;
		}
		else {
			int left = s.length() - min - 1;
			int right = s.length() - min;
			if (left < right) {
				sum += left;
			}
			else {
				sum += right;
			}
		}
		cout << min << " " << min_ind1 << " " << min_ind2 << endl;
		cout << sum << endl;
	}
	return 0;
}
