#include <iostream>
#include <queue>

using namespace std;

struct compare {
	bool operator()(const int& a, const int& b) {
		return a > b;
	}
};

int main() {
	priority_queue<int, vector<int> ,compare> pq;
	int N;
	cin >> N;
	int data;
	for (int i = 0; i < N; i++) {
		cin >> data;
		pq.push(data);
	}
	int tmp = 0;
	int ans = 0;
	while (pq.size() > 1) {
		tmp = pq.top(); pq.pop();
		if (pq.size() == 0) {
			pq.push(tmp);
			break;
		}
		tmp += pq.top(); pq.pop();
		ans += tmp;
		pq.push(tmp);
	}
	cout << ans;
}