#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> prime(1100001,true);
bool is_pelin(int _a) {
	string tmp = to_string(_a);
	
	for (int i = 0; i < tmp.size() / 2; i++) {
		if (tmp[i] != tmp[tmp.size() - 1 - i]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int N;
	cin >> N;
	prime[0] = prime[1] = false;
	for (int i = 2; i * i < 1100001; i++) {
		if (prime[i] == true) {
			for (int j = i * i; j < 1100001; j += i) {
				prime[j] = false;
			}
		}
	}
	for (int i = N; i < 1100001; i++) {
		if (prime[i]) {
			if (is_pelin(i) == true) {
				cout << i;
				break;
			}

		}
	}
}