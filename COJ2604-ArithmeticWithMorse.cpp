#include <iostream>
#include <string>
#include <stack>
using namespace std;

int parseMorse(string s) {
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

int evaluate(int A, int B, char op) {
	switch (op) {
		case '+':
			return A + B;
		case '*':
			return A * B;
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
		operators.push(s[0]);
		cin >> s;
		numbers.push(parseMorse(s));
	}
	return 0;
}
