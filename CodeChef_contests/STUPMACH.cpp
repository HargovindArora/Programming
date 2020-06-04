#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    vector<ll> s;
    ll minm = INT_MAX;
    int index;
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        if(x<minm){
            minm=x;
            index=i;
        }
        s.push_back(x);
    }
    if(index==0){
        cout << minm*n << endl;
        return;
    }
    int i=n-index;
    ll ans=0;
    ans += minm*i;
    while(index>0){

        n = index;
        ll minm = INT_MAX;
        for(int j=0; j<n; j++){
            if(s[j]<minm){
                minm=s[j];
                index=j;
            }
        }
        i = n-index;
        ans += minm*i;
    }
    cout << ans << endl;
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