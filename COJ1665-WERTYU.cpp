/*
 * =====================================================================================
 *
 *       Filename:  COJ1665-WERTYU.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/01/14 17:15:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eduardo Alberto Sanchez Alvarado (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;
char decode(const char &c) {
	switch (c) {
	case '1':
		return '`';
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return c - 1;
	case '-':
		return '0';
	case '=':
		return '-';
	case 'W':
		return 'Q';
	case 'E':
		return 'W';
	case 'R':
		return 'E';
	case 'T':
		return 'R';
	case 'Y':
		return 'T';
	case 'U':
		return 'Y';
	case 'I':
		return 'U';
	case 'O':
		return 'I';
	case 'P':
		return 'O';
	case '[':
		return 'P';
	case ']':
		return '[';
	case '\\':
		return ']';
	case 'S':
		return 'A';
	case 'D':
		return 'S';
	case 'F':
		return 'D';
	case 'G':
		return 'F';
	case 'H':
		return 'G';
	case 'J':
		return 'H';
	case 'K':
		return 'J';
	case 'L':
		return 'K';
	case ';':
		return 'L';
	case '\'':
		return ';';
	case 'X':
		return 'Z';
	case 'C':
		return 'X';
	case 'V':
		return 'C';
	case 'B':
		return 'V';
	case 'N':
		return 'B';
	case 'M':
		return 'N';
	case ',':
		return 'M';
	case '.':
		return ',';
	case '/':
		return '.';
	}
	return '\0';
}
int main(int argc, const char *argv[])
{
	string line;
	while (getline(cin, line)) {
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != ' ') {
				cout << decode(line[i]);
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}
