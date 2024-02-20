#include <iostream>
#include <queue>

using namespace std;

typedef struct node{
    int value;
    int seq;
}node;

struct compare{
    bool operator()(const node& a, const node& b){
        return a.value > b.value;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    int data;
    priority_queue<node, vector<node>, compare> pq;
    for(int i = 0; i < N; i++){
        cin >> data;
        pq.push({data, i});
        while(pq.top().seq <= i - M){
            pq.pop();
        }
        cout << pq.top().value << " ";
    }
}