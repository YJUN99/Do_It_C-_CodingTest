#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> adj[201];
bool visited[201];
int dp[201];
int dp_a[201];

int answer = 0x3fffffff;

int bfs_2(int now, int a, int b){
    fill(dp_a,dp_a+201,0x3fffffff);
    queue<pair<int,int>> que;
    que.push({now,0});
    dp_a[now] = 0;
    while(!que.empty()){
        pair<int,int> now_que = que.front();
        que.pop();
        for(auto &e : adj[now_que.first]){
            if(dp_a[e.first] < e.second + now_que.second){
                continue;
            }
            dp_a[e.first] = e.second + now_que.second;
            que.push({e.first , dp_a[e.first]});            
        }
    }
    return dp_a[a] + dp_a[b] + dp[now];
}

void bfs(int s){
    fill(dp,dp+201,0x3fffffff);
    queue<pair<int,int>> que;
    que.push({s, 0});
    dp[s] = 0;
    while(!que.empty()){
        pair<int,int> now = que.front();
        que.pop();
        for(auto &e : adj[now.first]){
            if(dp[e.first] < e.second + now.second) continue;
            dp[e.first] = e.second + now.second;
            que.push({e.first, e.second + now.second});
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i =0 ; i < fares.size(); i++){
        adj[fares[i][0]].push_back({fares[i][1],fares[i][2]});
        adj[fares[i][1]].push_back({fares[i][0],fares[i][2]});
    }
    bfs(s);
    for(int i = 1; i <= n; i++){
        if(dp[i] == 0x3fffffff) continue;
        int tmp = bfs_2(i,a,b);
        if(answer > tmp){
            answer = tmp;
        }        
    }
    return answer;
}