#include <queue>
#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	queue<int> que;
	vector<int> vec;
	for (int i = 1; i <= N; i++) {
		que.push(i);
	}

	while (!que.empty()) {
		for (int i = 0; i < M - 1; i++) {
			int tmp = que.front();
			que.pop();
			que.push(tmp);
		}
		vec.push_back(que.front());
		que.pop();
	}
	cout << '<';
	for (int i = 0; i < vec.size() - 1; i++) {
		cout << vec[i] << ", ";
	}
	cout << vec[vec.size() - 1] << '>';
}