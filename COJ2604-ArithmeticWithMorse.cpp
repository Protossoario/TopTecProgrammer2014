#include <iostream>
#include <string>
#include <stack>
using namespace std;

int parseMorse(const string &s) {
	int res = 0;
	for (unsigned int i = 0; i < s.length(); i++) {
		switch (s[i]) {
			case '.':
				res++;
				break;
			case '-':
				res += 5;
				break;
			case ':':
				res += 2;
				break;
			case '=':
				res += 10;
				break;
		}
	}
	return res;
}

int evaluate(const int &A, const int &B, const char &op) {
	switch (op) {
		case '+':
			return A + B;
		case '*':
			return A * B;
	}
	return 0;
}

int compareOps(const char &A, const char &B) {
	if (A == '+') {
		if (B == '+') {
			return 0;
		}
		return -1;
	}
	if (B == '+') {
		return 1;
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	stack<int> numbers;
	stack<char> operators;
	string s;
	int N, A, B;
	char op;
	cin >> N;
	cin >> s;
	numbers.push(parseMorse(s));
	for (int i = 0; i < N; i++) {
		cin >> s;
		while (!operators.empty() && (compareOps(operators.top(), s[0]) >= 0)) {
			B = numbers.top();
			numbers.pop();
			A = numbers.top();
			numbers.pop();
			op = operators.top();
			operators.pop();
			numbers.push(evaluate(A, B, op));
		}
		operators.push(s[0]);
		cin >> s;
		numbers.push(parseMorse(s));
	}
	while (!operators.empty()) {
		B = numbers.top();
		numbers.pop();
		A = numbers.top();
		numbers.pop();
		op = operators.top();
		operators.pop();
		numbers.push(evaluate(A, B, op));
	}
	cout << numbers.top() << endl;
	return 0;
}
