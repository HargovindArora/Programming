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

        void dijkstraSSSP(ll src,int n){

           map<ll, ll> dist;
            for(int i=1;i<=n;i++){
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
                        dist[dest] = nodeDist+childPair.second;
                        s.insert(make_pair(dist[dest], dest));
                    }
                }
            }
            for(auto d:dist){
                if(d.first==src){
                    continue;
                }
                if(d.second==INT_MAX){
                    cout << -1 << " ";
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
    g.dijkstraSSSP(src,n);
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


// #include <iostream>
// #include <cstdio>
// #include <string>
// #include <sstream> 
// #include <vector>
// #include <set>
// #include <map>
// #include <queue>
// #include <stack>
// #include <cmath>
// #include <algorithm>
// #include <cstring>
// #include <ctime>
// #include <cassert>


// using namespace std;

// const int N = 3000;
// const int W = 1e5;
// const int INF = 1e9;

// vector<pair<int, int>> g[N];
// int dist[N];
// bool visited[N];

// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while(t--)
//     {
//         int n, m;
//         scanf("%d %d", &n, &m);
//         assert(2 <= n && n <= N);
//         assert(1 <= m && m <= 1LL * n * (n - 1) / 2);

//         for(int i = 0; i < n; ++i) g[i].clear();
//         for(int i = 0; i < m; i++)
//         {
//             int v, u, w;
//             scanf("%d %d %d", &v, &u, &w);
//             assert(1 <= v && v <= n);
//             assert(1 <= u && u <= n);
//             assert(1 <= w && w <= W);
//             --v; --u;
//             g[v].push_back({u, w});
//             g[u].push_back({v, w});
//         }
//         int s;
//         scanf("%d", &s);
//         --s;

//         fill(dist, dist + n, INF);
//         fill(visited, visited + n, 0);
//         dist[s] = 0;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//         q.push({0, s});
//         while(!q.empty())
//         {
//             int v = q.top().second;
//             int d = q.top().first;
//             q.pop();
//             if(visited[v]) continue;
//             visited[v] = 1;
//             for(auto it: g[v])
//             {
//                 int u = it.first;
//                 int w = it.second;
//                 if(dist[v] + w < dist[u])
//                 {
//                     dist[u] = dist[v] + w;
//                     q.push({dist[u], u});
//                 }
//             }
//         }
//         for(int i = 0; i < n; ++i)
//         {
//             if(i == s) continue;
//             printf("%d ", (dist[i] != INF ? dist[i] : -1));
//         }
//         printf("\n");
//     }
//     return 0;
// }