/*
 * =====================================================================================
 *
 *       Filename:  COJ1979-ContestTiming.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2014 09:42:51 AM
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
	int D, H, M;
	cin >> D >> H >> M;
	if (D < 11) {
		cout << "-1" << endl;
	}
	else if (D == 11) {
		if (H == 11) {
			if (M == 11) {
				cout << "0" << endl;
			}
			else if (M > 11) {
				cout << (M - 11) << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (H > 11) {
			cout << (M + 49 + (H - 12) * 60) << endl;
		}
		else {
			cout << () << endl;
		}
	}
	return 0;
}
