#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int s2_sz = s2.size();
	
	deque<pair<char,int>> deq;
	int pos = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s2[pos] == s1[i]) {
			++pos;
		}
		else {
			pos = 0;
			if (s2[pos] == s1[i]) {
				++pos;
			}
		}
		deq.push_back({ s1[i], pos });
		if (pos == s2_sz ) {
			for (int j = 0; j < s2_sz; j++) {
				deq.pop_back();
			}
			if (deq.empty()) {
				pos = 0;
			}
			else {
				pos = deq.back().second;

			}
		}
	}
	if (deq.empty()) {
		cout << "FRULA";
		return 0;
	}
	for (auto& e : deq) {
		cout << e.first;
	}
	
}