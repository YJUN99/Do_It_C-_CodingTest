#include <iostream>
#include <string>
#include <vector>

using namespace std;
int cvt_int(string _s) {
	int ret = 0;
	for (int i = 0; i < _s.size(); i++) {
		ret = ret * 10 + _s[i] - '0';
	}
	return ret;
}
int main() {
	string s;
	cin >> s;
	vector<string> ms;
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			ms.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += s[i];
		}
	}
	ms.push_back(tmp);
	int ans = 0;
	tmp = "";
	vector<int> sum_vec;
	for (int i = 0; i < ms.size(); i++) {
		tmp = "";
		int tmp_sum = 0;
		for (int j = 0; j < ms[i].size(); j++) {
			if (ms[i][j] == '+') {
				tmp_sum += cvt_int(tmp);
				tmp = "";
			}
			else {
				tmp += ms[i][j];
			}
		}
		tmp_sum += cvt_int(tmp);
		sum_vec.push_back(tmp_sum);
	}
	ans = sum_vec[0];
	for (int i = 1; i < sum_vec.size(); i++) {
		ans -= sum_vec[i];
	}
	cout << ans;
}