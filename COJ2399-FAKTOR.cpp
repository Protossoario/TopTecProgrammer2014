#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
	int A, I;
	while (cin >> A >> I) {
		cout << (A * (I - 1) + 1) << endl;
	}
	return 0;
}
