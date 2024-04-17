#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string HexToBin(char s) {
	int a = s - '0';
	string ret = "";
	for (int i = 0; i < 3; i++) {
		if (a & 0x01 == 1) {
			ret += '1';
		}
		else {
			ret += '0';
		}
		a = a >> 1;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int main() {
	string s;
	cin >> s;
	if (s == "0") {
		cout << 0;
		return 0;
	}
	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		ans += HexToBin(s[i]);
	}
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == '1') {
			for (int j = i; j < ans.size(); j++) {
				cout << ans[j];
			}
			return 0;
		}
	}
	return 0;
}