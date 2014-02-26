#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, const char *argv[])
{
	int N, addr, ind1, ind2, sum1, sum2;
	ind1 = ind2 = sum1 = sum2 = 0;
	cin >> N;
	while (N--) {
		cin >> addr;
		int dist1 = abs(addr - ind1);
		int dist2 = abs(addr - ind2);
		if (dist1 < dist2) {
			sum1 += dist1;
			ind1 = addr;
		}
		else {
			sum2 += dist2;
			ind2 = addr;
		}
	}
	cout << (sum1 + sum2) << endl;
	return 0;
}
