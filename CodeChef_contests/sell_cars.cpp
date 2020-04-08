#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

    ll t;
    cin >> t;
    while(t--){

        ll n;
        cin >> n;
        vector<ll> v;
        v.reserve(10001);
        for(ll i=0; i<n; i++){
            ll x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end(), greater<ll>());
        ll profit=0;
        ll mod = 1000000007;
        profit += v[0];
        for(ll i=1; i<n; i++){
            v[i] = v[i] - i;
            if(v[i]<0){
                v[i] = 0;
                break;
            }
            profit += v[i];
        }
        cout << profit%mod << endl;
    }

    return 0;
}