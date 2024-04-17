#include <iostream>
#include <vector>

using namespace std;

void for_man(int swit, vector<int>& vec) {
	int SZ = vec.size();
	int idx = swit - 1;
	for (int i = idx; i < SZ; i += swit) {
		if (vec[i] == 1) {
			vec[i] = 0;
		}
		else {
			vec[i] = 1;
		}
	}
}

void for_woman(int swit, vector<int>& vec) {
	int SZ = vec.size();
	int idx = swit - 1;

	int left = idx - 1;
	int right = idx + 1;
	
	if (vec[idx] == 1) {
		vec[idx] = 0;
	}
	else {
		vec[idx] = 1;
	}
	while (left >= 0 && right < SZ) {
		if (vec[left] != vec[right]) break;
		if (vec[left] == 0) {
			vec[left] = vec[right] = 1;
		}
		else {
			vec[left] = vec[right] = 0;
		}
		left--;
		right++;
	}
}
int main() {
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	int M;
	int gen, swit;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> gen >> swit;
		if (gen == 1) {
			for_man(swit, vec);
		}
		else {
			for_woman(swit, vec);
		}
		//cout << "Step " << i + 1 << ": ";
		//for (auto& e : vec) {
		//	cout << e << " ";
		//}
		//cout << "\n";
	}
	for (int i = 0; i < vec.size(); i++) {
		if (i % 20 == 0 && i != 0) {
			cout << "\n";
		}
		cout << vec[i] << " ";
	}
}