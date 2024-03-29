#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> vec(N);
	vector<int> res;
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	int sum = 0;
	for (int i = 0; i < M; i++) {
		sum += vec[i];
	}
	int max_value = sum;
	for (int i = 0; i + M < N; i++) {
		sum -= vec[i];
		sum += vec[i + M];
		if (sum > max_value) {
			max_value = sum;
		}

	}
	cout << max_value;
}