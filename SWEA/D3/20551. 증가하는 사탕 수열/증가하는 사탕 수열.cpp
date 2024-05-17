#include <iostream>
#include <vector>

using namespace std;
/*

	5 8 4
	5 3 8

	2 6 5

	2 4 5
*/
int main() {
	int T;
	cin >> T;
	vector<int> vec(3);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> vec[j];
		}
		int ans = 0;
		for (int j = 1; j >= 0; j--) {
			if (vec[j + 1] <= vec[j]) {
				int tmp = vec[j];
				vec[j] = vec[j + 1] - 1;
				ans += tmp - vec[j];
			}
		}
		for (int j = 0; j < 3; j++) {
			if (vec[j] <= 0) ans = -1;
		}
		cout << "#" << i + 1 << " " << ans << "\n";
	}
}