#include <iostream>
#include <queue>
#include <cmath>

#define INF 0x3fffffff
using namespace std;

struct compare {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<int> minor_pq;
    priority_queue<int, vector<int>, compare> plus_pq;

    int data;
    for (int i = 0; i < N; i++) {
        cin >> data;

        if (data == 0) {
            int minor = 0;
            int plus = 0;
            if (!minor_pq.empty()) {
                minor = abs(minor_pq.top());
            }
            else minor = INF;
            if (!plus_pq.empty()) {
                plus = abs(plus_pq.top());
            }
            else plus = INF;

            if (minor <= plus && minor != INF) {
                cout << minor_pq.top() << "\n";
                minor_pq.pop();
            }
            else if (minor > plus && plus != INF) {
                cout << plus_pq.top() << "\n";
                plus_pq.pop();
            }
            else {
                cout << 0 << "\n";
            }
            
        }
        else {
            if (data < 0) {
                minor_pq.push(data);
            }
            else {
                plus_pq.push(data);
            }
        }
    }
}