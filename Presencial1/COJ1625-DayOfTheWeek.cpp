#include <iostream>
#include <string>
using namespace std;

int getMes(string m) {
	if (m == "JANUARY") {
		return 1;
	}
	else if (m == "FEBRUARY") {
		return 2;
	}
	else if (m == "MARCH") {
		return 3;
	}
	else if (m == "APRIL") {
		return 4;
	}
	else if (m == "MAY") {
		return 5;
	}
	else if (m == "JUNE") {
		return 6;
	}
	else if (m == "JULY") {
		return 7;
	}
	else if (m == "AUGUST") {
		return 8;
	}
	else if (m == "SEPTEMBER") {
		return 9;
	}
	else if (m == "OCTOBER") {
		return 10;
	}
	else if (m == "NOVEMBER") {
		return 11;
	}
	else if (m == "DECEMBER") {
		return 12;
	}
	return 0;
}

int calculaDiaSemanal(int d, int m, int a) {
	m-=2;
	if (m<1) m+=12;

	if (m>10) a--;
	return ( d + (int)(2.6*m-0.2) + 5*(a%4) + 4*(a%100) + 6*(a%400) )%7;
}

string getDia(int d) {
	switch (d) {
		case 1:
			return "MONDAY";
			break;
		case 2:
			return "TUESDAY";
			break;
		case 3:
			return "WEDNESDAY";
			break;
		case 4:
			return "THURSDAY";
			break;
		case 5:
			return "FRIDAY";
			break;
		case 6:
			return "SATURDAY";
			break;
		case 7:
			return "SUNDAY";
			break;
	}
	return "";
}

int main() {
	int N, a, d;
	string m;
	cin >> N;
	while (N--) {
		cin >> a >> m >> d;
		int dia = calculaDiaSemanal(d, getMes(m), a);
		cout << getDia(dia) << endl;
	}
	return 0;
}
