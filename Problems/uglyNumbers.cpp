#include<bits/stdc++.h>
using namespace std;

long long uglyNumberDP(int n){

    long long dp[n];
    int i2=0, i3=0, i5=0;
    long long mul2=2, mul3=3, mul5=5;
    long long uglyNum=1;
    dp[0] = 1;
    
    for(int i=1; i<n; i++){

        uglyNum = min(mul2, min(mul3, mul5));
        dp[i] = uglyNum;
        if(uglyNum==mul2){
            i2 += 1;
            mul2 = dp[i2]*2;
        }
        if(uglyNum==mul3){
            i3 += 1;
            mul3 = dp[i3]*3;
        }
        if(uglyNum==mul5){
            i5 += 1;
            mul5 = dp[i5]*5;
        }
    }
    return uglyNum;
}

void solve(){

    int n;
    cin >> n;
    cout << uglyNumberDP(n) << endl;
    return;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}