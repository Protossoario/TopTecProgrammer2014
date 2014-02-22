#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
#include <cmath>
using namespace std;
#define EMPTY '.'
#define WALL '#'
#define START '*'
#define EXIT 'X'
#define YKEY 'y'
#define YDOOR 'Y'
#define RKEY 'r'
#define RDOOR 'R'
#define BKEY 'b'
#define BDOOR 'B'
typedef pair<int, int> point;
#define point(x, y) make_pair(x, y)
char map[100][100];
int R, C;
vector<point> exits;
class Step {
public:
	int steps, min_dist, x, y;
	bool ykey, rkey, bkey;
	Step(int _x, int _y) {
		steps = 0;
		ykey = false;
		rkey = false;
		bkey = false;
		x = _x;
		y = _y;
		min_dist = INT_MAX;
	}
	Step(Step parent, int _x, int _y) {
		steps = parent.steps + 1;
		ykey = (parent.ykey || map[_y][_x] == YKEY);
		rkey = (parent.rkey || map[_y][_x] == RKEY);
		bkey = (parent.bkey || map[_y][_x] == BKEY);
		x = _x;
		y = _y;
		min_dist = INT_MAX;
		for (int i = 0; i < exits.size(); i++) {
			int dist = abs(x - exits[i].second) + abs(y - exits[i].first);
			if (dist < min_dist) {
				min_dist = dist;
			}
		}
	}
	bool operator<(const Step &s) const {
		return (steps + min_dist) < (s.steps + s.min_dist);
	}
};
bool is_blocked(Step curr, int x, int y) {
	return x < 0 || y < 0 || x >= C || y >= R || map[y][x] == WALL || (map[y][x] == RDOOR && !curr.rkey) || (map[y][x] == BDOOR && !curr.bkey) || (map[y][x] == YDOOR && !curr.ykey);
}
int solve(int x, int y) {
	priority_queue<Step> q;
	Step start(x, y);
	q.push(start);
	while (!q.empty()) {
		Step curr = q.top();
		q.pop();
		cout << "popped: " << curr.x  << " " << curr.y << endl;
		cout << "steps: " << curr.steps << " mindist: " << curr.min_dist << endl;
		cout << "rkey: " << curr.rkey << endl;
		cout << "ykey: " << curr.ykey << endl;
		cout << "bkey: " << curr.bkey << endl;
		if (map[curr.y][curr.x] == EXIT) {
			return curr.steps;
		}
		if (!is_blocked(curr, curr.x - 1, curr.y)) {
			cout << "pushing: " << curr.x - 1 << " " << curr.y << endl;
			q.push(Step(curr, curr.x - 1, curr.y));
		}
		if (!is_blocked(curr, curr.x + 1, curr.y)) {
			cout << "pushing: " << curr.x + 1 << " " << curr.y << endl;
			q.push(Step(curr, curr.x + 1, curr.y));
		}
		if (!is_blocked(curr, curr.x, curr.y - 1)) {
			cout << "pushing: " << curr.x << " " << curr.y - 1 << endl;
			q.push(Step(curr, curr.x, curr.y - 1));
		}
		if (!is_blocked(curr, curr.x, curr.y + 1)) {
			cout << "pushing: " << curr.x << " " << curr.y + 1 << endl;
			q.push(Step(curr, curr.x, curr.y + 1));
		}
	}
	return INT_MAX;
}
int main(int argc, const char *argv[]) {
	string str_in;
	point start;
	while (cin >> R >> C && R != 0) {
		for (int i = 0; i < R; i++) {
			cin >> str_in;
			for (int j = 0; j < C; j++) {
				map[i][j] = str_in[j];
				if (map[i][j] == EXIT) {
					exits.push_back(point(i, j));
				}
				else if (map[i][j] == START) {
					start = point(i, j);
				}
			}
		}
		cout << solve(start.second, start.first) << endl;
	}
	return 0;
}
