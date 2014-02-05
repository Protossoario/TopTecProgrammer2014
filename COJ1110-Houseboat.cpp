/*
 * =====================================================================================
 *
 *       Filename:  COJ1110-Houseboat.cpp
 *
 *    Description:  Entradas numero de casos. Para cada caso, X y Y representan la localizacion de la casa. El area que se pierde incrementa en 50 millas cuadradas.
 *
 *        Version:  1.0
 *        Created:  02/01/14 14:23:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eduardo Alberto Sanchez Alvarado (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cmath>
using namespace std;
#define PI 3.14
#define AREA 50

int calcYears(double X, double Y) {
	return (int) (((pow(X, 2) + pow(Y, 2)) * PI / 2) / AREA + 1);
}

int main() {
	int N;
	double X, Y;
	scanf("%i", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lf %lf", &X, &Y);
		printf("Property %i: This property will begin eroding in year %i.\n", i, calcYears(X, Y));
	}
	printf("END OF OUTPUT.");
}
