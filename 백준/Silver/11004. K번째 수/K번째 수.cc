#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> vec(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin() + 1, vec.end());
    cout << vec[M];
}