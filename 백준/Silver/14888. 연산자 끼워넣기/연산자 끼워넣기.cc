#include <iostream>
#include <vector>

using namespace std;

int max_value = -0x3fffffff;
int min_value = 0x3fffffff;
void DFS(vector<int> vec, vector<int> ope, int idx, int sum) {
	if (idx == vec.size()) {
		if (sum > max_value) {
			max_value = sum;
		}
		if (sum < min_value) {
			min_value = sum;
		}
		return;
	}
	else {
		if (ope[0] > 0) {
			ope[0]--;
			sum += vec[idx];
			DFS(vec, ope, idx + 1, sum);
			ope[0]++;
			sum -= vec[idx];
		}
		if (ope[1] > 0) {
			ope[1]--;
			sum -= vec[idx];
			DFS(vec, ope, idx + 1, sum);
			ope[1]++;
			sum += vec[idx];
		}
		if (ope[2] > 0) {
			ope[2]--;
			sum *= vec[idx];
			DFS(vec, ope, idx + 1, sum);
			ope[2]++;
			sum /= vec[idx];
		}
		if (ope[3] > 0) {
			ope[3]--;
			sum /= vec[idx];
			DFS(vec, ope, idx + 1, sum);
			ope[3]++;
			sum *= vec[idx];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> vec(N);
	vector<int> ope(4, 0);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> ope[i];
	}
	DFS(vec, ope, 1, vec[0]);
	cout << max_value << "\n" << min_value;
}