/*
 * =====================================================================================
 *
 *       Filename:  COJ1115-SequenceSumPossibilities.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/17/14 17:43:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eduardo Alberto Sanchez Alvarado (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
	int N, num;
	cin >> N;
	for (int cases = 1; cases <= N; cases++) {
		cin.ignore(5, ' ');
		cin >> num;
		long n0 = 3;
		int i = 2;
		int sum = 0;
		while (n0 <= num) {
			if ((num - n0) % i == 0) {
				sum++;
			}
			i++;
			n0 += i;
		}
		cout << cases << " " << sum << endl;
	}
	return 0;
}
