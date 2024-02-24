#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> men(N);
    for(int i = 0 ; i < N; i++){
        cin >> men[i];
    }
    sort(men.begin(),men.end());
    
    int sum = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        sum += men[i];
        ans += sum;
    }
    cout << ans;
}