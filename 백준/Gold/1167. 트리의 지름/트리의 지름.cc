#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
    int dest;
    int cost;
}node;

vector<node> adj[100001];
vector<bool> visited(100001,false);

int fartest_node;
int longgest_dest = -1;
void DFS(int _now, int _costsum){
    if(longgest_dest < _costsum){
        fartest_node = _now;
        longgest_dest = _costsum;
    }
    for(auto& e:adj[_now]){
        node tmp = e;
        if(visited[tmp.dest] == true) continue;
        visited[tmp.dest] = true;
        DFS(tmp.dest, _costsum + tmp.cost);
    }
}

int main(){
    int N;
    cin >> N;
    int s,d,c;
    for(int i = 0 ; i < N; i++){
        cin >> s;
        while(1){
            cin >> d;
            if(d == -1){
                // 입력탈출
                break;
            }
            cin >> c;
            adj[s].push_back({d,c});
            
        }
    }
    visited[1] = true;
    DFS(1,0);
    longgest_dest = -1;
    fill(visited.begin(), visited.end(), false);
    visited[fartest_node] = true;
    DFS(fartest_node,0);
    cout << longgest_dest;
    
}