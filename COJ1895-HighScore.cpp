/*
 * =====================================================================================
 *
 *       Filename:  COJ1895-HighScore.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/23/14 12:22:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eduardo Alberto Sanchez Alvarado (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <climits>
using namespace std;
class Node {
public:
	Node * left, * right;
	int weightLeft, weightRight;
	Node() {
		left = right = NULL;
		weightLeft = weightRight = INT_MAX;
	}
};
int min(const int &a, const int &b) {
	return a < b ? a : b;
}
int minOffset(const char &c) {
	return min(c - 'A', 'Z' - c + 1);
}
int main(int argc, const char *argv[])
{
	string s;
	int N, sum, last_dist;
	Node * head, * tail;
	cin >> N;
	while (N--) {
		cin >> s;
		sum = last_dist = 0;
		head = tail = new Node();
		if (s[0] != 'A') {
			sum += minOffset(s[0]);
		}
		for (unsigned int i = 1; i < s.length(); i++) {
			last_dist++;
			if (s[i] != 'A') {
				sum += minOffset(s[i]);
				Node * temp = tail;
				tail = new Node();
				temp->right = tail;
				tail->left = temp;
				temp->weightRight = tail->weightLeft = last_dist;
				last_dist = 0;
			}
		}
		if (head != tail) {
			head->left = tail;
			tail->right = head;
			head->weightLeft = tail->weightRight = last_dist + 1;
			tail = head;
			if (head->weightLeft < head->weightRight) {
				sum += head->weightLeft;
				head = head->left;
			}
			else {
				sum += head->weightRight;
				tail = head->right;
			}
			while (head != tail->right) {
				if (head->weightLeft < tail->weightRight) {
					sum += head->weightLeft;
				}
				else {
					sum += tail->weightRight;
					tail = tail->right;
				}
			}
			while (head->right != head) {
				Node * temp = head->right;
				head->right = head->right->right;
				delete temp;
			}
		}
		delete head;
		cout << sum << endl;
	}
	return 0;
}
