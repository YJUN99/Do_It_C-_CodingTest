#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> my_split(string str, char deli) {
	vector<int> ret;
	size_t start = 0;
	size_t end = str.find(deli);
	while (end != string::npos) {
		int tmp = stoi(str.substr(start, end));
		ret.push_back(tmp);
		start = end + 1;
		end = str.find(deli, start);
	}
	int tmp = stoi(str.substr(start));
	ret.push_back(tmp);
	return ret;
}
int main() {
	string s, e;
	
	cin >> s >> e;
	if (s == e) {
		cout << "24:00:00";
		return 0;
	}
	vector<int> s_time;
	vector<int> e_time;
	

	s_time = my_split(s, ':');
	e_time = my_split(e, ':');
	
	int second = e_time[2] - s_time[2];
	if (second < 0) {
		second += 60;
		e_time[1] -= 1;
	}
	int minute = e_time[1] - s_time[1];
	if (minute < 0) {
		minute += 60;
		e_time[0] -= 1;
	}
	int hour = e_time[0] - s_time[0];
	if (hour < 0) {
		hour += 24;
	}
	printf("%02d:%02d:%02d", hour, minute, second);
}