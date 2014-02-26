#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
bool isPrime(int N) {
	if (N == 1) {
		return false;
	}
	if (N == 2) {
		return true;
	}
	if (N % 2 == 0) {
		return false;
	}
	int i = 3;
	while ((i * i) <= N) {
		if (N % i == 0) {
			return false;
		}
		i += 2;
	}
	return true;
}
int main(int argc, const char *argv[])
{
	string N0, N;
	int perm, primality = 0;
	cin >> N;
	N0 = N;
	do {
		perm = atoi(N.c_str());
		if (isPrime(perm)) {
			primality++;
		}
		next_permutation(N.begin(), N.end());
	} while (N != N0);
	cout << primality << endl;
	return 0;
}
