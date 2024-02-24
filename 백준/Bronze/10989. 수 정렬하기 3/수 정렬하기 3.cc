#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int N;
	int data;
	cin >> N;
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		cin >> data;
		m[data]++;
	}
	for (int i = 1; i <= 10000; i++) {
		while (m[i] >= 1) {
			cout << i << "\n";
			m[i]--;
		}
	}
}