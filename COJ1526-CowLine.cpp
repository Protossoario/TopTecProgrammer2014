#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
	int N, K;
	string op;
	vector<int> perm;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		perm.push_back(i);
	}
	while (K--) {
		cin >> op;
		if (op == "P") {
		}
		else {
		}
	}
	return 0;
}
