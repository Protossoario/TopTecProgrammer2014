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
	int N, sum, ind1, max, left_gap, right_gap, max_ind1, max_ind2;
	bool A;
	cin >> N;
	while (N--) {
		cin >> s;
		max = sum = 0;
		left_gap = right_gap = ind1 =  max_ind1 = max_ind2 = -1;
		A = false;
		for (unsigned int i = 0; i < s.length(); i++) {
			if (s[i] != 'A') {
				sum += minOffset(s[i]);
				if (A) {
					A = false;
					int dist = i - ind1;
					if (dist >= max) {
						max = dist;
						max_ind1 = ind1;
						max_ind2 = i;
					}
				}
			}
			else if (!A) {
				ind1 = i;
				A = true;
			}
		}
		if (A) {
			A = false;
			int dist = s.length() - ind1;
			if (dist >= max) {
				max = dist;
				max_ind1 = ind1;
				max_ind2 = s.length();
			}
		}
		bool stop = false;
		int i = 1;
		while (!stop && i < s.length()) {
			if (s[i] != 'A') {
				stop = true;
				left_gap = i;
			}
			i++;
		}
		int j = i;
		while (j < s.length()) {
			if (s[j] != 'A') {
				i = j;
			}
			j++;
		}
		right_gap = j - i;
		if (max_ind1 == -1) {
			sum += s.length() - 1;
		}
		else if (max_ind1 == 0) {
			sum += s.length() - max;
		}
		else if (max_ind2 == s.length()) {
			sum += s.length() - max - 1;
		}
		else {
			int left = max_ind1 - 1;
			int right = s.length() - max_ind2;
			int travel;
			if (left < right) {
				travel = left * 2 + right;
			}
			else {
				travel = right * 2 + left;
			}
			sum += min(min(travel, s.length() - left_gap), s.length() - right_gap);
		}
		cout << sum << endl;
	}
	return 0;
}
