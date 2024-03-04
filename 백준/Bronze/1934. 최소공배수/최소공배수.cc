#include <iostream>

using namespace std;

int GCD(int a, int b) {
	while (b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	int N, M;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a;
		int ans = 0;
		cin >> N >> M;
		a = GCD(N, M);
		ans = a * (N / a) * (M / a);
		cout << ans << "\n";
	}
}