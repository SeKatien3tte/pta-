#include <iostream>

using namespace std;

int main() {
	int a, b, c, t = 0;
	int n;
	cin >> n;
	for (a = n; a < n + 4; a++) {
		for (b = n; b < n + 4; b++) {
			for (c = n; c < n + 4; c++) {
				if (a == b || a == c || b == c)
					continue;
				else {
					t++;
					if (t == 6) {
						cout << a << b << c << endl;
						t = 0;
					}
					else {
						cout << a << b << c << " ";
					}
				}
			}
		}
	}
	return 0;
}