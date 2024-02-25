#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string> 

using namespace std;

vector<string> board;
bool visited[101][101];
int N, M;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

typedef struct node {
    int y;
    int x;
    int cnt;
};

void BFS(pair<int, int> _now) {
    queue<node> que;
    que.push({ _now.first, _now.second , 1});
    visited[_now.first][_now.second] = true;
    while (!que.empty()) {
        node tmp_now = que.front();
        que.pop();
        if (tmp_now.y == N - 1 && tmp_now.x == M - 1) {
            cout << tmp_now.cnt;
            return;
        }
        for (int i = 0; i < 4; i++) {
            node next = { tmp_now.y + dir[i][0], tmp_now.x + dir[i][1] , tmp_now.cnt + 1};
            if (next.y >= 0 && next.y < N && next.x >= 0 && next.x < M && board[next.y][next.x] == '1') {
                if (visited[next.y][next.x] == true) continue;
                visited[next.y][next.x] = true;
                que.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        board.push_back(s);
    }
    BFS({ 0,0 });
    return 0;
}
