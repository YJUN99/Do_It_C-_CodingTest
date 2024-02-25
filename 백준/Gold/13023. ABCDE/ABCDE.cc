#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<bool> visited(2001);
vector<int> adj[2001];
int N,M,answer = 0;

void DFS(int _now, int _count){
    if(_count == 5){
        answer = 1;
        return;
    }
    else{
        for(auto &e : adj[_now]){
            if(visited[e] == true) continue;
            visited[e] = true;
            DFS(e,_count + 1);
            if(answer == 1) return;
            visited[e] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    cin >> N >> M;

    int a,b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[j] = false;
        }
        visited[i] = true;
        DFS(i, 1);   
    }
    cout << answer;
    return 0;
}
