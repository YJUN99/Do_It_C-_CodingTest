#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[300001];
bool visited[300001];
vector<int> ans;
queue<pair<int,int>> que;
void BFS(int _now, int _target) {
	que.push({ _now, 0 });
	visited[_now] = 1;
	while (!que.empty()) {
		pair<int, int> now = que.front(); que.pop();
		int now_dist = now.second;
		int now_node = now.first;
		if (now_dist == _target + 1) {
			break;
		}
		if (now_dist == _target) {
			ans.push_back(now_node);
		}
		for (auto& e : adj[now_node]) {
			if (visited[e] == true) continue;
			visited[e] = true;
			que.push({ e,now_dist + 1 });
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	BFS(X, K);
	sort(ans.begin(), ans.end());
	if (ans.empty()) {
		cout << -1;
		return 0;
	}
	else {
		for (auto& e : ans) {
			cout << e << "\n";
		}
	}
}