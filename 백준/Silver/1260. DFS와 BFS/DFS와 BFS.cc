#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[1001];
vector<bool> visited(1001);

void DFS(int _now){
    visited[_now] = true;
    cout << _now << " ";
    for(auto &next: adj[_now]){
        if(visited[next] == true) continue;
        visited[next] = true;
        DFS(next);
    }
}

void BFS(int _now){
    queue<int> que;
    que.push(_now);
    visited[_now] = true;
    
    while(!que.empty()){
        int tmp = que.front();
        cout << tmp << " ";
        que.pop();
        for(auto &next : adj[tmp]){
            if(visited[next] == true) continue;
            visited[next] = true;
            que.push(next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, M, K;
    
    cin >> N >> M >> K;
    
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= N ;i++){
        sort(adj[i].begin(), adj[i].end());
    }
    DFS(K);
    cout << "\n";
    fill(visited.begin(),visited.end(),false);
    BFS(K);
    return 0;
}
