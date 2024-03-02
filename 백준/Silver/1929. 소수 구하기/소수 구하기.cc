#include <iostream>
#include <vector>

using namespace std;

vector<bool> prime(1000001,true);

int main() {
	int N, M;
	cin >> N >> M;
	prime[0] = prime[1] = false;
	for (int i = 2; i * i < 1000001; i++) {
		if (prime[i] == true) {
			for (int j = i * i; j < 1000001; j += i) {
				prime[j] = false;
			}
		}
	}
	for (int i = N; i <= M; i++) {
		if (prime[i] == true) {
			cout << i << "\n";
		}
	}
}