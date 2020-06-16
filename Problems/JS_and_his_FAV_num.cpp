#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n, k, x;
    cin >> n >> k >> x;
    int *freq = new int[1111](); // Initialized with zero

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    int *temp = new int[1111]();
    
    while(k--){
        for(int i=0; i<1111; i++){
            temp[i] = freq[i];
        }
        int parity = 0;
        for(int i=0; i<1111; i++){
            if(freq[i]>0){
                int cur = x^i;
                int update = freq[i]/2;
                if(parity==0){
                    update += (freq[i]&1);
                }
                temp[i] -= update;
                temp[cur] += update;
                parity ^= (freq[i]&1);
            }
        }
        for(int i=0; i<1111; i++){
            freq[i] = temp[i];
        }
    }

    int minm = INT_MAX, maxm = INT_MIN;

    for(int i=0; i<1111; i++){
        if(freq[i]>0){
            maxm = max(i, maxm);
            minm = min(i, minm);
        }
    }

    cout << maxm << " " << minm;

    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();

    return 0;
}