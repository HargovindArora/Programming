#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define MOD 1000000007
using namespace std;

void combinationUtil(ll arr[], ll n, ll r, ll index, ll data[], ll i, ll k, ll &count){
    // Current cobination is ready, print it 
    if (index == r) {
        ll minm = INT_MAX;
        ll maxm = INT_MIN;
        for (ll j = 0; j < r; j++){
            minm = min(minm, data[j]);
            maxm = max(maxm, data[j]);
        }
        ll diff = (maxm-minm);
        if(diff<=k){
            count = (count+1)%MOD;
        }
        return; 
    } 
    if (i >= n) 
        return; 
    data[index] = arr[i]; 
    combinationUtil(arr, n, r, index + 1, data, i + 1, k, count);
    combinationUtil(arr, n, r, index, data, i + 1, k, count); 
}

void solve(){

    ll n, l, k;
    ll *a = new ll[n];
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    ll *data = new ll[k];
    ll count=0;
    combinationUtil(a, n, l, 0, data, 0, k, count);
    cout << count << endl;
}

int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}