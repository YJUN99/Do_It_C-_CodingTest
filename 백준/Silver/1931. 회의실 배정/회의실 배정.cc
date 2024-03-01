#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node {
	int start;
	int end;
};

bool cmp(const node& a, const node& b) {
	if (a.end < b.end) {
		return 1;
	}
	else if (a.end == b.end) {
		if (a.start < b.start) {
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int s, d;
	vector<node> vec;
	for (int i = 0; i < N; i++) {
		cin >> s >> d;
		vec.push_back({ s, d });
	}
	sort(vec.begin(), vec.end(), cmp);
	//for (auto& e : vec) {
	//	cout << e.start << " " << e.end << "\n";
	//}
	int answer = 0;
	int finish_time = 0;
	for (auto& e : vec) {
		if (e.start >= finish_time) {
			answer++;
			finish_time = e.end;
		}
		else {
			if (e.end < finish_time) {
				finish_time = e.end;
			}
		}
	}
	cout << answer;
}