#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

char a2[1001], b2[1001];
int a[1001], b[1001], s, ss, s3, x, c[10001];

int main() {
	scanf("%s",a2);
	scanf("%s",b2);
	s = strlen(a2);
	ss = strlen(b2);
	for (int i = 0; i < s; i++) {
		a[s - i] = a2[i] - '0';
	}
	for (int i = 0; i < ss; i++) {
		b[ss - i] = b2[i] - '0';
	}
	for (int i = 1; i <= s; i++) {
		x = 0;
		for (int j = 1; j <= ss; j++) {
			c[i+j-1] = a[i] * b[j] + x + c[i+j-1];
			x = c[i+j-1] / 10;
			c[i+j-1] %= 10;
		}
		c[i+ss] = x;
	}
	s3 = s + ss;
	while (c[s3] == 0 && s3 > 1) {
		s3--;
	}
	for (int i = s3; i >= 1; i--) {
		cout << c[i];
	}
	//cout << endl;
	return 0;
}
