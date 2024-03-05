#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[10001];
vector<bool> visited(10001, false);
queue<int> que;

int BFS(int _now) {
	int cnt = 0;
	que.push(_now);
	visited[_now] = true;
	while (!que.empty()) {
		int now = que.front(); que.pop();
		cnt++;
		for (auto& e : adj[now]) {
			if (visited[e] == true) continue;
			que.push(e);
			visited[e] = true;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, d, s;
	vector<int> ans;
	int cnt_bfs = -1;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> s >> d;
		adj[d].push_back(s);
	}
	for (int i = 1; i <= N; i++) {
		fill(visited.begin(), visited.end(), false);
		int cnt_ret = BFS(i);
		if (cnt_ret > cnt_bfs) {
			cnt_bfs = cnt_ret;
			ans.clear();
			ans.push_back(i);
		}
		else if (cnt_ret == cnt_bfs) {
			ans.push_back(i);
		}
	}
	for (auto& e : ans) {
		cout << e << " ";
	}
}