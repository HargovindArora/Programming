#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class DSU{

    public:
        vector<ll> parent, size;
        ll total_component;

        DSU(ll n){
            parent.resize(n);
            size.resize(n);
            for(ll i=0; i<n; i++){
                parent[i] = i;
            }
            for(ll i=0; i<n; i++){
                size[i] = 1;
            }
            total_component = n;
        }

        ll getSuperParent(ll x){
            if(x==parent[x]){
                return x;
            }
            else{
                return (parent[x]=getSuperParent(parent[x]));
            }
        }

        void join(ll x, ll y){
            ll super_parent_x = getSuperParent(x);
            ll super_parent_y = getSuperParent(y);
            if(super_parent_x != super_parent_y){
                parent[super_parent_x] = super_parent_y;
                size[super_parent_y] += size[super_parent_x];
                size[super_parent_x] = 0;
                total_component--;
            }
        }
};

void solve(){

    ll n, m;
    cin >> n >> m;
    DSU g(n);
    for(int i=0; i<m; i++){
        ll x, y;
        cin >> x >> y;
        g.join(x, y);
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
        ll x = g.getSuperParent(i);
        ans += (n-g.size[x]);
    }
    cout << (ll)(ans/2) << endl;

}

int main(){

    solve();

    return 0;
}

