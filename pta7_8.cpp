#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iomanip>
#define PI acos(-1)

using namespace std;

int main() {
	string str, str1, str2;
	string city_ascii = "city_ascii";
	string lat = "lat"; string lng = "lng";
	string city_inform[6];
	int city, latt, lngg;
	int count1 = 0, start1 = 0, flag = 0;
	getline(cin, str1);
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == ',') {
			city_inform[count1] = str1.substr(start1, i - start1);
			count1++;
			start1 = i + 1;
		}
	}
	city_inform[5] = str1.substr(start1);
	for (int i = 0; i < 6; i++) {
		if (city_inform[i] == city_ascii)
			city = i;
		if (city_inform[i] == lat)
			latt = i;
		if (city_inform[i] == lng)
			lngg = i;
	}
	static string city_informs[900];
	for (str; getline(cin, str);) {	
			if (str == "=====")
				break;	
			int count = 0, start = 0;
			for (int i = 0; i < str.length(); i++) {
				if (str[i] == ',') {
					city_inform[count] = str.substr(start, i - start);
					count++;
					start = i + 1;
				}
			}
			city_inform[5] = str.substr(start);		
				city_informs[flag] = city_inform[city];
				city_informs[flag + 1] = city_inform[latt];
				city_informs[flag + 2] = city_inform[lngg];
				flag += 3;		
	}
	for (str; getline(cin, str);) {
		int  start = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ','){
				str1 = str.substr(start, i - start);
				start = i + 1;
				break;
			}		
		}
		str2 = str.substr(start);
		double lat1 = 0, lng1 = 0, lat2 = 0, lng2 = 0, distance = 0;
		for (int i = 0; i < flag; i+=3) {
			if (city_informs[i] == str1){
				lat1 = stof(city_informs[i + 1]);
				lng1 = stof(city_informs[i + 2]);
				break;
			}				
		}
		for (int i = 0; i < flag; i += 3) {
			if (city_informs[i] == str2) {
				lat2 = stod(city_informs[i + 1]);
				lng2 = stod(city_informs[i + 2]);
				break;
			}
		}
		lat1 = lat1 * (PI / 180); lat2 = lat2 * (PI / 180); lng1 = lng1 * (PI / 180); lng2 = lng2 * (PI / 180);
		distance = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lng1 - lng2));
		distance = distance * 6378.1;
		cout << setprecision(1) << fixed << distance << endl;
	}
}