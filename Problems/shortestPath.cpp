#include<bits/stdc++.h>
#define ll long long int
using namespace std;


class graph{

    private:
        unordered_map<ll, list<pair<ll, ll>>> m;
    
    public:
        void addEdge(ll u, ll v, ll cost=6){
            m[u].push_back(make_pair(v, cost));
            m[v].push_back(make_pair(u, cost));
        }

        void dijkstraSSSP(ll src, ll n){
            
            map<ll, ll> dist;
            for(int i=1; i<=n; i++){
                dist[i] = INT_MAX;
            }
            set<pair<ll, ll>> s;
            dist[src] = 0;
            s.insert(make_pair(0, src));
            while(!s.empty()){
                auto p = *(s.begin());
                ll node = p.second;
                ll nodeDist = p.first;
                s.erase(s.begin());
                for(auto childPair:m[node]){

                    if(nodeDist+childPair.second < dist[childPair.first]){
                        ll dest = childPair.first;
                        auto f = s.find(make_pair(dist[dest], dest));
                        if(f!=s.end()){
                            s.erase(f);
                        }
                        dist[dest] = nodeDist + childPair.second;
                        s.insert(make_pair(dist[dest], dest));
                    }

                }
            }
            for(auto d:dist){
                if(d.first==src){
                    continue;
                }
                if(d.second==INT_MAX){
                    cout << "-1 ";
                    continue;
                }
                cout << d.second << " ";
            }
            cout << endl;
        }
};


void solve(){

    graph g;
    ll n, m;
    cin >> n >> m;
    for(ll i=1; i<=m; i++){
        ll x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    ll src;
    cin >> src;
    g.dijkstraSSSP(src, n);

}


int main(){

    ll q;
    cin >> q;
    while(q--){

        solve();

    }

    return 0;
}