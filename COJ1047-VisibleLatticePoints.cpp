/*
 * =====================================================================================
 *
 *       Filename:  COJ1047-VisibleLatticePoints.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/01/14 16:49:50
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
int GCF(int A, int B) {
	int C;
	while (A != 0) {
		C = A;
		A = B % A;
		B = C;
	}
	return B;
}
int main(int argc, const char *argv[])
{
	int N, C;
	int arr[1000];
	arr[0] = 3;
	for (int i = 1; i < 1000; i++) {
		arr[i] = arr[i - 1];
		int count = 0;
		for (int j = 1; j <= i; j++) {
			if (GCF(i + 1, j) == 1) {
				count++;
			}
		}
		arr[i] += count * 2;
	}
	cin >> C;
	for (int i = 1; i <= C; i++) {
		cin >> N;
		cout << i << " " << N << " " << arr[N - 1] << endl;
	}
	return 0;
}
