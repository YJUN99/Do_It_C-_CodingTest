#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
bool visited[1001];

void BFS(int now){
    if(visited[now]){
        return;
    }
    visited[now] = 1;
    for(auto &e : adj[now]){
        BFS(e);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    int N, M;
    cin >> N >> M;
    int s, d;
    for(int i = 0; i < M; i++){
        cin >> s >> d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    for(int i = 1; i <= N; i++){
        if(visited[i] == false){
            ans++;
            BFS(i);
        }
    }
    cout << ans;
}