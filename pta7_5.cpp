#include <iostream>
#include <string>
# include <stdio.h>


using namespace std;

int main() {
	int flag;
	string b = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
	for (string s; getline(cin, s);) {
		flag = 0;
		char a;
		for (int k = 0; k < s.length(); k++) {
			a = s[k];
			for (int i = 0; i < 53; i++) {
				char j = b[i];
				if (a == j && a != 32) {
				flag = 1;
				break;
			}
				if (a == 32) {
					flag = 0;
					break;
			}		
		}
			if (flag == 0)
					break;		
	}
	if (flag == 0)
			cout << 0 << endl;
	if (flag == 1)
			cout << 1 << endl;
	}
}