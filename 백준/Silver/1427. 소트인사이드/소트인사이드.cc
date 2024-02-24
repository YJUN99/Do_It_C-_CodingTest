#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string N;
    cin >> N;
    sort(N.rbegin(), N.rend());
    for(auto &e : N){
        cout << e;
    }
    
    
    
}