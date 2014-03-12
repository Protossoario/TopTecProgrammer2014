/*
 * =====================================================================================
 *
 *       Filename:  COJ1428-Packets.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/11/14 21:19:05
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
	int packets[6];
	int suma;
	bool end = false;
	while (!end) {
		end = true;
		suma = 0;
		for (int i = 0; i < 6; i++) {
			cin >> packets[i];
			if (packets[i] != 0) {
				end = false;
			}
		}
		if (!end) {
			suma += packets[5];
			suma += packets[4];
			packets[0] -= 11 * packets[4];
			if (packets[0] < 0) packets[0] = 0;
			suma += packets[3];
			if (packets[3] * 5 <= packets[1]) {
				packets[1] -= packets[3] * 5;
				if (packets[1] < 0) packets[1] = 0;
			}
			else {
				packets[0] -= (5 * (packets[3] - (packets[1] / 5)) + (packets[1] % 5)) * 4;
				if (packets[0] < 0) packets[0] = 0;
				packets[1] = 0;
			}
			suma += packets[2] / 4;
			packets[2] %= 4;
			if (packets[2] > 0) {
				suma++;
				int aux1 = 36 - packets[2] * 9;
				int aux2;
				if (packets[2] == 1 && packets[1] >= 5) {
					aux2 = 5;
				}
				else if (packets[2] == 2 && packets[1] >= 3) {
					aux2 = 3;
				}
				else if (packets[3] == 3 && packets[1] >= 1) {
					aux2 = 1;
				}
				else {
					aux2 = packets[1];
				}
				packets[1] -= aux2;
				if (packets[1] < 0) packets[1] = 0;
				packets[0] -= aux1 - aux2 * 4;
				if (packets[0] < 0) packets[0] = 0;
			}
			suma += packets[1] / 9;
			packets[1] %= 9;
			if (packets[1] > 0) {
				suma++;
				packets[0] -= 36 - packets[1] * 4;
			}
			suma += packets[0] / 36;
			packets[0] %= 36;
			if (packets[0] > 0) {
				suma++;
			}
			cout << suma << endl;
		}
	}
	return 0;
}
