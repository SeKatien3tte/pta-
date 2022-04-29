#include <iostream>
#include <string>

using namespace std;

int main() {
	int n = 0, num = 0, flag = 0;
	string str, strf, strl;
	string str1 = "";
	cin >> n;
	string var[52];
	cin.get();
	for (str; getline(cin, str);) {
		if (str[0] >= 65 && str[0] <= 90 && str[1] == '=') {
			if (str.length() == 2){
				strf = str[0];
				strl = "";
			}
			strf = str[0];
			strl = str.substr(2);
			var[num] = strf;
			var[++num] = strl;
			num++;
		}
		else {
			for (int i = 0; i < str.length(); i++) {
				flag = 0;
				if (str[i] == '$') {
					flag = 1;
					if (str[i + 1] < 65 || str[i + 1] > 90) {
						if (str[i + 1] == '$') {
							cout << "$";
							i++;
						}
						else {
							cout << "$" << str.substr(i + 1, 1);
							i++;
						}
					}
					else {
						str1 = "";
						for (int k = 0; k < num; k+=2) {
							if (str.substr(i + 1, 1) == var[k]) {
								str1 = var[k + 1];	
							}	
						}
						if (str1 != "") {
							cout << str1;
							i++;
						}	
						if (str1 == "") {
							cout << "";
							i++;
						}
					}
				}
				if (flag == 0)
					cout << str[i] ;
			}
			printf("\n");
		}
	}
}