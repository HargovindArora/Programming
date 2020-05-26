#include<iostream>
#define ll long long int
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll dp[n+1] = {0};
        dp[0] = 2, dp[1] = 3;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        cout << dp[n-1] << endl;
    }

    return 0;
}