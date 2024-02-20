#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v;
    int data;
    for(int i = 0; i < N; i++){
        cin >> data;
        v.push_back(data); 
    }
    sort(v.begin(), v.end());
    for(auto &e : v){
        cout << e << "\n";
    }
}