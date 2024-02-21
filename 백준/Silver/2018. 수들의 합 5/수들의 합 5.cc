#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;
    while(left <= right && right <= N){
        if(sum == N){
            ans++;
            right++;
            sum += right;
        }
        else if(sum < N){
            right++;
            sum += right;
        }
        else{
            sum -= left;
            left++;
        }
        
    }
    cout << ans;
    return 0;
}