#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;


ll raise_to(ll a, ll n){
    ll ans = 1;

    while(n>0){
        int last_bit = n&1;
        if(last_bit){
            ans = ans*a;
        }
        a = a*a;
        n = n>>1;
    }

    return ans;
}

void solve(){

    ll n;
    cin >> n;
    if(n==1){
        cout << 1 << endl;
        return;
    }
    ll ans = raise_to(n,3)-raise_to(n-2,3);
    cout << ans << endl;
    return;
}

int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}