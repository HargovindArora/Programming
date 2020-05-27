#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>


ll lengthOfLIS(const vector<ll>& v) {
    ll n = v.size();
    vector<ll> tail(1, 0);
    tail[0] = v[0];
    for (int i = 1; i < n; ++i) {
        if(v[i] < tail[0]) {
            tail[0] = v[i];
        }
        else if(v[i] > tail.back()) {
            tail.push_back(v[i]);
        }
        else {
            int index = lower_bound(tail.begin(), tail.end(), v[i]) - tail.begin() ; 
            tail[index] = v[i];
        }
    }

    return tail.size();
}

int main() {
    sync;
    int n ;
    cin >> n;
    vector < ll > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << lengthOfLIS(v) ;

    return 0;
}