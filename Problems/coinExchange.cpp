#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// ll exchangeCoinsBottomUp(ll n){

//     unordered_map<ll, ll> dp;
//     dp[0] = 0;
//     dp[1] = 1;
//     dp[2] = 2;
//     dp[3] = 3;
//     for(ll i=4; i<=n; i++){

//         ll t1, t2, t3;
//         t1 = t2 = t3 = 0;
//         t1 = dp[i/2];
//         t2 = dp[i/3];
//         t3 = dp[i/4];
//         ll x = t1+t2+t3;
//         dp[i] = max(i, x);
//     }
//     return dp[n];
// }

ll exchangeCoinsBottomUp(ll n,map<ll,ll> &dp){

    if(n==1 || n==2 || n==3){
        return n;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    ll  ans1 = exchangeCoinsBottomUp(n/2,dp)+exchangeCoinsBottomUp(n/3,dp)+exchangeCoinsBottomUp(n/4,dp);
    ll ans = max( ans1 , n );
    return dp[n] =  ans;
}

void solve(){

    ll n;
    cin >>n;
    map<ll, ll> dp;
    cout << exchangeCoinsBottomUp(n, dp) << endl;

}

int main(){

    solve();

    return 0;
}