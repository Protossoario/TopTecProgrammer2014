#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double area(const double A, const double B) {
	return pow((A * B) / (A + B),2);
}

void trimZeroes(char * s, int n) {
	s = strchr(s, '.');
	if (s != NULL) {
		while (n >= 0) {
			n--;
			if (*s != '\0') {
				s++;
			}
			else {
				break;
			}
		}
		*s-- = '\0';
		while (*s == '0') {
			*s-- = '\0';
		}
		if (*s == '.') {
			*s = '\0';
		}
	}
}

int main() {
	int N;
	double A, B;
	scanf("%i", &N);
	while (N--) {
		char result[12];
		scanf("%lf %lf", &A, &B);
		sprintf(result, "%.4lf", area(A, B));
		trimZeroes(result, 4);
		printf("%s\n", result);
	}
}
