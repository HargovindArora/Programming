#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    int a[n], b[n];
    int minma = INT_MAX, minmb = INT_MAX, maxm = INT_MIN;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        cin >> a[i];
        mp[a[i]]++;
        minma = min(minma, a[i]);
        maxm = max(maxm, a[i]);
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        mp[b[i]]--;
        minmb = min(minmb, b[i]);
        maxm = max(maxm, b[i]);
    }

    for(int i=0; i<=maxm; i++){
        if(mp[i]%2!=0){
            cout << -1 << endl;
            return;
        }
    }
    int flag=1;
    for(int i=0; i<maxm; i++){
        if(mp[i]!=0){
            flag = 0;
            break;
        }
    }
    if(flag==1){
        cout << 0 << endl;
        return;
    }

    int x = n/2;
    if(x%2==0){
        if(minma<minmb){
            ll ans = x*minma;
            if(x>1){
                ans += minma;
            }
            cout << ans << endl;
        }
        else{
            ll ans = x*minmb;
            if(x>1){
                ans += minmb;
            }
            cout << ans << endl;
        }
    }
    else{
        if(minma<minmb){
            ll ans = x*minma+minmb;
            cout << ans << endl;
        }
        else{
            ll ans = x*minmb + minma;
            cout << ans << endl;
        }
    }

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