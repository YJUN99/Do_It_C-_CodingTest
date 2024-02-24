#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> ans(N,-1);
    stack<pair<int,int>> stk; 
    int data;
    for(int i = 0; i < N; i++){
        cin >> data;
        while(!stk.empty() && stk.top().second < data){
            ans[stk.top().first] = data;
            stk.pop();
        }
        stk.push({i,data});
    }
    
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
}