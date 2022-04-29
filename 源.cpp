#include <iostream>
#include <stdlib.h>
using namespace std;
inline bool is_hex(char c) {
    if (c > 47 && c < 58 || c > 64 && c < 71 || c > 96 && c < 103)
        return true; // TODO
    else
        return false;
}
unsigned char parse_byte(unsigned char hi, unsigned char lo) {
    int ans = 0; int f = 0;
    char c;
    c = 48;
    if (hi > 47 && hi < 58) {
        for (int i = 0; i < 10; i++) {
            if (hi == c) {
                ans += f * 16;
                break;
            }
            else {
                c++;
                f++;
            }
        }
    }
    if (hi > 64 && hi < 71 || hi > 96 && hi < 103) {
        c = 65;
        f = 10;
        for (int i = 0; i < 6; i++) {
            if (hi == c || hi == c + 32) {
                ans += f * 16;
                break;
            }
            else {
                c++;
                f++;
            }
        }
    }
    c = 48;
    if (lo > 47 && lo < 58) {
        for (int i = 0; i < 10; i++) {
            if (lo == c) {
                ans += f;
                break;
            }
            else {
                c++;
                f++;
            }
        }
    }
    if (lo > 64 && lo < 71 || lo > 96 && lo < 103) {
        c = 65;
        f = 10;
        for (int i = 0; i < 6; i++) {
            if (lo == c || lo == c + 32) {
                ans += f;
                break;
            }
            else {
                c++;
                f++;
            }
        }
    }
    return ans;
}

int main() {
    for (char hi, lo; cin >> hi >> lo;) {
        cout << hi << lo << ": ";
        if (is_hex(hi) && is_hex(lo)) { // ÖØÓÃ
            cout << (int)parse_byte(hi, lo) << endl;
        }
        else {
            cout << "invalid" << endl;
        }
    }
}