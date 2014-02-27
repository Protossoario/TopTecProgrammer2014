#include <iostream>
#include <string>
using namespace std;
int board[26][26];
int P, Q;
int move_x[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int move_y[8] = {2, -2, 1, -1, 2, -2, 1, -1};
string result;
char column(int j) {
	return 'A' + j;
}
bool knightsTour(int step, int x, int y) {
	if (step == P * Q) {
		return true;
	}
	int new_x, new_y;
	for (int i = 0; i < 8; i++) {
		new_x = x + move_x[i];
		new_y = y + move_y[i];
		if (new_x >= 0 && new_y >= 0 && new_x < P && new_y < Q && board[new_x][new_y] == -1) {
			board[new_x][new_y] = step;
			result.push_back(column(new_x));
			result.append(to_string(new_y + 1));
			if (knightsTour(step + 1, new_x, new_y)) {
				return true;
			}
			else {
				board[new_x][new_y] = -1;
				result.pop_back();
				result.pop_back();
				if (new_y > 8) {
					result.pop_back();
				}
			}
		}
	}
	return false;
}
int main(int argc, const char *argv[])
{
	int N;
	cin >> N;
	for (int k = 1; k <= N; k++) {
		cin >> P >> Q;
		for (int i = 0; i < P; i++) {
			for (int j = 0; j < Q; j++) {
				board[i][j] = -1;
			}
		}
		result = "A1";
		board[0][0] = 0;
		cout << "Scenario #" << k << endl;
		if (knightsTour(1, 0, 0)) {
			cout << result << endl;
		}
		else {
			cout << "impossible" << endl;
		}
		cout << endl;
	}
	return 0;
}
