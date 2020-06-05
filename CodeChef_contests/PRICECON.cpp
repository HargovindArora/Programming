#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n, k;
    cin >> n >> k;
    int a[n];
    ll sum1=0, sum2=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum1 += a[i];
        if(a[i]>k){
            sum2 += k;
        }
        else{
            sum2 += a[i];
        }
    }
    cout << sum1-sum2 << endl;
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