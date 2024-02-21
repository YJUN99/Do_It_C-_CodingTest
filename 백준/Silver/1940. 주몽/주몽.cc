#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bsearch(vector<int> _v, int _s , int _N,int _target){
    int start = _s + 1;
    int end = _N - 1;
    int middle = 0;
    int sum = 0;
    while(start <= end){
        middle = (start + end) / 2;
        sum = _v[middle] + _v[_s];
        
        if(sum == _target){
            return 1;
        }
        else if(sum < _target){
            start = middle + 1;
        }
        else{
            end = middle - 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    int answer = 0;
    cin >> N >> M;
    
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < N; i++){
        answer += bsearch(v,i,N,M);   
    }
    cout << answer;
    return 0;
}