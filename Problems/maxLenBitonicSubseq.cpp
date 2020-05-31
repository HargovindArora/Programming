#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int maxLenBitonicDP(int *a, int n){

    int lis[n] = {0};
    for(int i=0; i<n; i++){
        lis[i] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                int curlen = 1+lis[j];
                lis[i] = max(curlen, lis[i]);
            }
        }
    }

    int lds[n] = {0};
    for(int i=0; i<n; i++){
        lds[i] = 1;
    }
    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(a[j] < a[i]){
                int curLen = 1+lds[j];
                lds[i] = max(curLen, lds[i]);
            }
        }
    }

    int maxLen = 0;
    for(int i=0; i<n; i++){
        int curLen = lds[i] + lis[i] -1;
        maxLen = max(curLen, maxLen);
    }
    return maxLen;
}

void solve(){

    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << maxLenBitonicDP(a, n) << endl;
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