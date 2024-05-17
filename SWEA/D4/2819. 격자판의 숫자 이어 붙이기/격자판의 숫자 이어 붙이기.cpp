#include <iostream>
#include <string>
#include <set>

using namespace std;

bool visited[4][4];
int board[4][4];
int dir[4][2] = {
	{1,0},{-1,0},{0,1},{0,-1}
};
set<string> se;
void DFS(int(* board)[4], string s, int nowy, int nowx) {
	if (s.length() == 7) {
		se.insert(s);
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int nexty = nowy + dir[i][0];
			int nextx = nowx + dir[i][1];

			if (nexty < 0 || nexty >= 4 || nextx < 0 || nextx >= 4) {
				continue;
			}
			//if (visited[nexty][nextx] == true) continue;
			//visited[nexty][nextx] = true;
			DFS(board, s + to_string(board[nexty][nextx]), nexty, nextx);
			//visited[nexty][nextx] = false;
		}
	}
}

void initialization() {
	for (int q = 0; q < 4; q++) {
		for (int w = 0; w < 4; w++) {
			visited[q][w] = false;
		}
	}
}

int main() {
	int TC;
	cin >> TC;
	
	for (int i = 1; i <= TC; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> board[j][k];
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				//initialization();
				//visited[j][k] = true;
				DFS(board, to_string(board[j][k]), j, k);
			}
		}
		//for (auto& e : se) {
		//	cout << e << "\n";
		//}
		cout << "#" <<i<<" " << se.size() << "\n";
		se.clear();
	}
}