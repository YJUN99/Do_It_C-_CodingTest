#include <iostream>
#include <vector>

using namespace std;

vector<int> prime(1001, 1);

int main() {
	int N, M;
	cin >> N >> M;
	prime[0] = prime[1] = 0;
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (prime[j] == 1) {
				prime[j] = 0;
				cnt++;
			}
			if (cnt == M) {
				cout << j;
				return 0;
			}
		}
	}

}