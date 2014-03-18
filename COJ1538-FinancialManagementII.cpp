#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;
string dollarFormat(double n) {
	ostringstream str;
	str << fixed << setprecision(2) << (n < 0 ? -n : n);
	string temp = str.str();
	int ind = temp.find('.');
	string res = temp.substr(ind, 3);
	ind -= 3;
	while (ind >= 0) {
		res = ',' + temp.substr(ind, 3) + res;
		ind -= 3;
	}
	res = temp.substr(0, 3 + ind) + res;
	if (res[0] == ',') {
		res = res.substr(1, string::npos);
	}
	res = (n < 0 ? "-" : "") + res;
	return res;
}
int main(int argc, const char *argv[])
{
	int N;
	double ave, balance;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		ave = 0;
		for (int j = 0; j < 12; j++) {
			cin >> balance;
			ave += balance;
		}
		ave /= 12;
		cout << i << " " << "$" << dollarFormat(ave) << endl;
	}
	return 0;
}
