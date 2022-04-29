#include <iostream>
#include <string>

using namespace std;

int main() {
	int min, max;
	int page_size, page_num, page, offset, record_count;
	cin >> min >> max;
	cin.get();
	string s, str[3];
	for (s; getline(cin, s);) {
		int count = 0, start = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 32) {
				str[count] = s.substr(start, i - start);
				count++;
				start = i + 1;
			}
		}
		str[2] = s.substr(start);
		page_size = stoi(str[0], 0, 10); page_num = stoi(str[1], 0, 10); record_count = stoi(str[2], 0, 10);
		if (page_size <= min)
			page_size = min;
		else if (page_size >= max)
			page_size = max;
		if (record_count != 0 && record_count % page_size != 0)
			page = record_count / page_size + 1;
		else if (record_count != 0 && record_count % page_size == 0)
			page = record_count / page_size;
		else
			page = 0;
		if (page_num > page)
			page_num = page;
		if (page_num <= 0 && page != 0)
			page_num = 1;
		if (page_num <= 0 && page == 0)
			page_num = 1;
		if (page_num > 0 && page_num <= page)
			offset = (page_num - 1) * page_size;
		else
			offset = 0;
		cout << page_size << " " << page << " " << page_num << " " << offset << endl;
	}
}