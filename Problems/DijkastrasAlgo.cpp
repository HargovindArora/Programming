#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Graph{

    private:
        unordered_map<ll, list<pair<ll, ll>>> m;
    
    public:
        void addEdge(ll u, ll v, ll cost){
            m[u].push_back(make_pair(v, cost));
            m[v].push_back(make_pair(u, cost));
        }

        void dijkstraSSSP(ll src){

            unordered_map<ll, ll> dist;
            for(auto i:m){
                dist[i.first] = INT_MAX;
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
                        dist[dest] = nodeDist+childPair.second;
                        s.insert(make_pair(dist[dest], dest));
                    }
                }
            }
            for(auto d:dist){
                if(d.first==src){
                    continue;
                }
                cout << d.second << " ";
            }
            cout << endl;

        }
};

void solve(){

    ll n, m;
    Graph g;
    cin >> n >> m;
    for(ll i=0; i<m; i++){
        ll x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }
    ll src;
    cin >> src;
    g.dijkstraSSSP(src);
    return;
}

int main(){

    int t;
    cin >> t;
    while(t--){

        solve();

    }

    return 0;
}