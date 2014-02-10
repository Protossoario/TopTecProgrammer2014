#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MOD 12345678910

class Node {
public:
	vector<Node *> children;
	void appendChild(Node * n);
};

void Node::appendChild(Node * n) {
	children.push_back(n);
}

long value(Node * n) {
	if (n->children.size() == 0) {
		return 1;
	}
	long sum = 0;
	for (vector<Node *>::iterator it = n->children.begin(); it != n->children.end(); it++) {
		sum = (sum + value(*it)) % MOD;
	}
	sum = (sum * 2) % MOD;
	return sum;
}

void remove(Node * n) {
	for (vector<Node *>::iterator it = n->children.begin(); it != n->children.end(); it++) {
		remove(*it);
	}
	delete n;
}

int main() {
	int N;
	bool paren;
	Node * n1, * n2;
	stack<Node *> s;
	vector<Node *> parents;
	cin >> N;
	while (N--) {
		cin >> paren;
		if (!paren) {
			n1 = new Node();
			if (s.size() == 0) {
				parents.push_back(n1);
			}
			else {
				n2 = s.top();
				n2->appendChild(n1);
			}
			s.push(n1);
		}
		else {
			s.pop();
		}
	}
	long sum = 0;
	for (vector<Node *>::iterator it = parents.begin(); it != parents.end(); it++) {
		sum = (sum + value(*it)) % MOD;
	}
	cout << sum << endl;
	for (vector<Node *>::iterator it = parents.begin(); it != parents.end(); it++) {
		remove(*it);
	}
	return 0;
}
