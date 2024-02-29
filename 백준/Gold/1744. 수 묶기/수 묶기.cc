#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct compare {
	bool operator()(const int& a, const int& b) {
		return a > b;
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, compare> mpq;
	priority_queue<int> ppq;
	int data;
	for (int i = 0; i < N; i++) {
		cin >> data;
		if (data > 0) {
			ppq.push(data);
		}
		else {
			mpq.push(data);
		}
	}
	int ans = 0;
	while (!mpq.empty()) {
		int tmp1 = mpq.top(); mpq.pop();
		if (mpq.empty()) {
			ans += tmp1;
			break;
		}
		else {
			int tmp2 = mpq.top(); mpq.pop();
			ans += (tmp1 * tmp2);
		}
	}
	while (!ppq.empty()) {
		int tmp1 = ppq.top(); ppq.pop();
		if (ppq.empty()) {
			ans += tmp1;
			break;
		}
		else {
			int tmp2 = ppq.top(); ppq.pop();
			if (tmp1 * tmp2 < tmp1 + tmp2) {
				ans += tmp1 + tmp2;
			}
			else {
				ans += tmp1 * tmp2;
			}
		}
	}
	cout << ans;
}