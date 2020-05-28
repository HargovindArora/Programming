#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;

ll countWays(int n, int m){

    ll dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        if(i>m){
            dp[i] = (dp[i-1]+dp[i-m])%MOD;
        }
        if(i==m){
            dp[i] = 2;
        }
        if(i<m || i==1){
            dp[i] = 1;
        }
    }
    return dp[n];
} 

void solve(){

    int n, m;
    cin >> n >> m;
    cout << countWays(n,m)%MOD << endl;

}

int main(){

    int t;
    cin >> t;
    while(t--){

        solve();

    }

    return 0;
}