#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;


void solve(){

    ll n, m;
    cin >> n >> m;
    unordered_map<ll, ll> mp;
    for(ll i=0; i<=n; i++){
        mp[i] = 0;
    }
    for(int i=1; i<=m; i++){
        ll x, y, w;
        cin >> x >> y >> w;
        mp[x]+=w;
    }
    ll ans = 0;
    for(int i=2; i<=n; i+=2){
        ans += abs(mp[i]-mp[i-1]);
    }
    cout << ans << endl;
    return;
}

int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}