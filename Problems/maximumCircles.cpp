#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

bool compare(pair<ll, ll> p1, pair<ll, ll> p2){
    return p1.second<p2.second;
}

int main(){

    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for(int i=0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        v.push_back(make_pair(x-y, x+y));
    }
    int remove = 0;
    sort(v.begin(), v.end(), compare);
    ll dist = v[0].second;
    for(int i=1; i<n; i++){
        if(dist <= v[i].first){
            dist = v[i].second;
        }
        else{
            remove++;
        }
    }
    cout << remove << endl;

    return 0;
}