#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    set<int> s;
    int data;
    for(int i = 0; i < N;i++){
        cin >> data;
        s.insert(data);
    }
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> data;
        auto p = s.find(data);
        if(p == s.end()){
            cout << 0 << "\n";
        }
        else{
            cout << 1 << "\n";
        }
    }
}