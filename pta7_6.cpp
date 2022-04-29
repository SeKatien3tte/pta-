#include <iostream>
#include <string>

using namespace std;

int main() {
	string t = "\\";
	for (string s; getline(cin, s);) {
		for (int i = 0; i < s.length(); i++) {
			char z = s[i];
			if (z == 92) {
				char x = s[++i];
				if (x == 110) {
					printf("\n");
				}
				else if (x == 116) {
					printf("\t");
				}
				else
					cout << x;
			}
			else
				cout << z;
		}
		printf("\n");
	}
}