#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    queue<int> que; 
    for(int i = 1; i <=  N; i++){
        que.push(i);   
    }
    while(! (que.size() <= 1)){
        que.pop();
        que.push(que.front());
        if(que.size() <= 1) break;
        que.pop();
    }
    cout << que.front();
}