#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		vector<int> candy(N);
		for (int j = 0; j < N; j++) {
			cin >> candy[j];
		}
		sort(candy.begin(), candy.end());
		int ans = 0x3fffffff;
		for (int j = M - 1; j < N; j++) {
			if (ans > candy[j] - candy[j - M + 1]) {
				ans = candy[j] - candy[j - M + 1];
			}
		}
		cout << "#" << i+1 << " " << ans << "\n";
	}
}