#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    ll n;
    cin >> n;
    ll a[n], b[n];
    ll minma = INT_MAX, minmb = INT_MAX, maxma = INT_MIN, maxmb = INT_MIN;
    map<ll, ll> map_a, map_b, mp;
    
    for(ll i=0; i<n; i++){
        cin >> a[i];
        map_a[a[i]]++;
        mp[a[i]]++;
        minma = min(minma, a[i]);
        maxma = max(maxma, a[i]);
    }
    for(ll i=0; i<n; i++){
        cin >> b[i];
        map_b[b[i]]++;
        mp[b[i]]++;
        minmb = min(minmb, b[i]);
        maxmb = max(maxmb, b[i]);
    }

    ll minm = min(minma, minmb);
    ll maxm = max(maxma, maxmb);

    for(auto x:mp){
        if(x.second%2!=0){
            cout << -1 << endl;
            return;
        }
    }

    bool flag=1;
    sort(a, a+n);
    sort(b, b+n);

    for(ll i=0; i<n; i++){
        if(a[i] != b[i]){
            flag = 0;
            break;
        }
    }
    if(flag==1){
        cout << 0 << endl;
        return;
    }

    vector<ll> diff;
    for(auto x:mp){
        if(map_a[x.first] == map_b[x.first]){
            continue;
        }
        else{
            ll count = abs(map_a[x.first]-map_b[x.first])/2;
            while(count--){
                diff.push_back(x.first);
            }
        }
    }

    ll ans = 0;
    sort(diff.begin(), diff.end());
    if((diff.size())%2!=0){
        cout << -1 << endl;
        return;
    }
    else{
        for(ll i=0; i<diff.size()/2; i++){
            if(diff[i]>2*minm){
                ans += 2*minm;
            }
            else{
                ans += diff[i];
            }
        }
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