// https://www.spoj.com/problems/GNYR09F/
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

int dp[105][105][2];

int adjBitCount(int n, int k, int first){

    if(n==0){
        return 0;
    }
    if(n==1){
        if(k==0){
            return 1;
        }
        else if(k<0){
            return 0;
        }
        else{
            return 0;
        }
    }

    if(dp[n][k][first]!=-1){
        return dp[n][k][first];
    }

    int val = -1;
    if(first==1){
        val = adjBitCount(n-1, k-1, 1) + adjBitCount(n-1, k, 0); 
    }
    else{
        val = adjBitCount(n-1, k, 1) + adjBitCount(n-1, k, 0);
    }

    return dp[n][k][first] = val;
}

void solve(){
    
    int num, n, k;
    cin >> num >> n >> k;
    memset(dp, -1, sizeof(dp));
    int x = adjBitCount(n, k, 1);
    x += adjBitCount(n, k, 0);
    cout << num << " " << x << endl;

    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        
        solve();
        
    }

    return 0;
}