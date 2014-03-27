/*
 * =====================================================================================
 *
 *       Filename:  COJ1277-Postscript.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/14 22:28:30
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
using namespace std;

string C5[][5] = {
    {".***..", "*...*.", "*****.", "*...*.", "*...*."},
    {"****..", "*...*.", "****..", "*...*.", "****.."},
    {".****.", "*...*.", "*.....", "*.....", ".****."},
    {"****..", "*...*.", "*...*.", "*...*.", "****.."},
    {"*****.", "*.....", "***...", "*.....", "*****."},
    {"*****.", "*.....", "***...", "*.....", "*....."},
    {".****.", "*.....", "*..**.", "*...*.", ".***.."},
    {"*...*.", "*...*.", "*****.", "*...*.", "*...*."},
    {"*****.", "..*...", "..*...", "..*...", "*****."},
    {"..***.", "...*..", "...*..", "*..*..", ".**..."},
    {"*...*.", "*..*..", "***...", "*..*..", "*...*."},
    {"*.....", "*.....", "*.....", "*.....", "*****."},
    {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."},
    {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."},
    {".***..", "*...*.", "*...*.", "*...*.", ".***.."},
    {"****..", "*...*.", "****..", "*.....", "*....."},
    {".***..", "*...*.", "*...*.", "*..**.", ".****."},
    {"****..", "*...*.", "****..", "*..*..", "*...*."},
    {".****.", "*.....", ".***..", "....*.", "****.."},
    {"*****.", "*.*.*.", "..*...", "..*...", ".***.."},
    {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."},
    {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."},
    {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."},
    {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."},
    {"*...*.", ".*.*..", "..*...", "..*...", "..*..."},
    {"*****.", "...*..", "..*...", ".*....", "*****."},
};

int main(int argc, const char *argv[])
{
	char page[60][60];
	string command, font, text;
	int row, col, font_size;
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++) {
			page[i][j] = '.';
		}
	}
	cin >> command;
	do {
		if (command == ".EOP") {
			for (int i = 0; i < 60; i++) {
				for (int j = 0; j < 60; j++) {
					cout << page[i][j];
				}
				cout << endl;
			}
			cout << endl << "------------------------------------------------------------" << endl << endl;
			for (int i = 0; i < 60; i++) {
				for (int j = 0; j < 60; j++) {
					page[i][j] = '.';
				}
			}
			continue;
		}
		cin >> font >> row;
		row--;
		col = 0;
		font_size = font[1] - '0';
		if (command == ".P") {
			cin >> col;
			col--;
			cin.ignore(1, ' ');
			getline(cin, text);
		}
		else if (command == ".L") {
			cin.ignore(1, ' ');
			getline(cin, text);
		}
		else if (command == ".R") {
			cin.ignore(1, ' ');
			getline(cin, text);
			if (font_size == 1) {
				col = 60 - (text.length() - 2);
			}
			else {
				col = 60 - (text.length() - 2) * 6;
			}
		}
		else {
			cin.ignore(1, ' ');
			getline(cin, text);
			if (font_size == 1) {
				col = 30 - (text.length() - 2) / 2;
			}
			else {
				col = 30 - (text.length() - 2) * 3;
			}
		}
		if (font_size == 1) {
			for (int i = 1; i < (int) (text.length() - 1); i++) {
				int print_col = col + i - 1;
				if (print_col >= 0 && print_col < 60 && text[i] != ' ') {
					page[row][print_col] = text[i];
				}
			}
		}
		else {
			for (int i = 1; i < (int) (text.length() - 1); i++) {
				if (text[i] != ' ') {
					for (int j = 0; j < 5; j++) {
						int print_row = row + j;
						for (int k = 0; k < 6; k++) {
							int print_col = col + 6 * (i - 1) + k;
							if (print_col >= 0 && print_col < 60 && print_row >= 0 && print_row < 60) {
								page[print_row][print_col] = C5[text[i] - 'A'][j][k];
							}
						}
					}
				}
			}
		}
	} while (cin >> command);
	return 0;
}
