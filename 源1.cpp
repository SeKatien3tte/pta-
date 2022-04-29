#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool parse_ipv4(const string& s, uint32_t& ip) {
    string s1;
    int num[4] = { 0, 0, 0, 0 };
    int st = 0; int fi = 0; int flagp = 0;
    int flag = 0;
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] < '0' || s[i] > '9') && s[i] != '.') {
            flag = 1;
            break;
        }
        if (s[i] == '.') {
            if (i == s.length() - 1) {
                flag = 1;
                break;
            }
            s1 = s.substr(st, i - st);
            flagp++;
            for (int k = 0; k < s1.length(); k++) {
                if (s1[k] > 47 && s1[k] < 58) {
                    if (s1[0] == '0' && s1.length() < 2 || s1.length() < 4 && s1[0] != '0') {
                        num[fi] = stoi(s1);
                        if (num[fi] >= 0 && num[fi] <= 255) {
                            st = i + 1;
                            fi++;
                            break;
                        }
                        else {
                            flag = 1;
                            break;
                        }
                    }
                    else {
                        flag = 1;
                        break;
                    }
                }
                else {
                    flag = 1;
                    break;
                }
            }
            if (flagp == 3) {
                s1 = s.substr(i + 1);
                for (int j = 0; j < s1.length(); j++) {
                    if (s1[0] == '0' && s1.length() > 1) {
                        flag = 1;
                        break;
                    }
                    if (s1[j] < '0' || s1[j] >'9') {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    num[3] = stoi(s1);
                }
            }
            if (flag == 1)
                break;
        }
    }
    ip = num[0] + num[1] * 256 + num[2] * 256 * 256 + num[3] * 256 * 256 * 256;
    if (flag == 1)
        return false;
    else
        return true;
}

int main() {
    for (string s; getline(cin, s);) {
        cout << s << ": ";
        uint32_t ip = 0;
        if (parse_ipv4(s, ip)) {
            cout << ip << '\n';
        }
        else {
            cout << "invalid\n";
        }
    }
    cout << flush;
}