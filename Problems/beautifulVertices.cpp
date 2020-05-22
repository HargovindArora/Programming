#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class graph{

    private:
        map<ll, list<ll>> l;
    
    public:
        void addEdge(ll x, ll y){
            l[x].push_back(y);
        }

        void dfsHelper(ll src, unordered_map<ll, bool> &visited,unordered_map<ll, ll> &children, unordered_map<ll, ll> &parent){
            visited[src] = true;
            for(ll nbr:l[src]){
                children[src]++;
                parent[nbr] = src;
                if(!visited[nbr]){
                    dfsHelper(nbr, visited, children, parent);
                }
            }
        }

        void dfs(ll n){
            unordered_map<ll, bool> visited;
            unordered_map<ll, ll> children;
            unordered_map<ll, ll> parent;
            for(ll i=1; i<=n; i++){
                parent[i] = 0;
            }
            for(ll i=1; i<=n; i++){
                children[i] = 0;
            }
            for(ll i=1; i<=n; i++){
                visited[i] = false;
            }
            for(auto x:l){
                ll node = x.first;
                if(!visited[node]){
                    dfsHelper(node, visited, children, parent);
                }
            }
            ll count=0;
            for(ll i=1; i<=n; i++){
                if(parent[i]>0 and (children[i]>children[parent[i]])){
                    count++;
                }
            }
            cout << count << endl;
        }

};

void solve(){

    ll n, m;
    cin >> n >> m;
    graph g;
    for(int i=0; i<m; i++){
        ll x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    g.dfs(n);
}

int main(){

    solve();

    return 0;
}