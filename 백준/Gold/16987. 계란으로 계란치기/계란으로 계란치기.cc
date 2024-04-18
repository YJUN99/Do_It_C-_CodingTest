#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct node {
	int hp;
	int weight;
}node;
int ans = 0;
void solution(vector<node> &vec, int now) {
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].hp <= 0) cnt++;
	}
	if (ans < cnt) ans = cnt;
	if (now == vec.size()) {
		return;
	}
	else {
		int flag = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (i == now) continue;
			if (vec[i].hp <= 0 || vec[now].hp <= 0) continue;
			vec[i].hp -= vec[now].weight;
			vec[now].hp -= vec[i].weight;
			solution(vec, now + 1);
			flag = 1;
			vec[i].hp += vec[now].weight;
			vec[now].hp += vec[i].weight;
		}
		if (flag == 0) solution(vec, now + 1);
	}
}
int main() {
	int N;
	cin >> N;
	
	int h, w;
	vector<node> vec;
	for (int i = 0; i < N; i++) {
		cin >> h >> w;
		vec.push_back({ h,w });
	}
	solution(vec, 0);
	cout << ans;

}