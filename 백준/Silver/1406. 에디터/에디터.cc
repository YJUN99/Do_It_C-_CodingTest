#include <iostream>
#include <string>
#include <list>

using namespace std;


int main() {

	string str;
	list<char> li;
	list<char>::iterator it;
	cin >> str;
	int N;
	char cmd, data;
	for (auto& e : str) {
		li.push_back(e);
	}
	it = li.end();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == 'P') {
			cin >> data;
			li.insert(it, data);
		}
		else if (cmd == 'L') {
			if (it == li.begin()) {
				continue;
			}
			it--;
		}
		else if (cmd == 'D') {
			if (it == li.end()) {
				continue;
			}
			it++;
		}
		else {
			if (it != li.begin()) {
				it--;
				it = li.erase(it);
			}
		}
		
	}
	for (auto& e : li) {
		cout << e;
	}

}