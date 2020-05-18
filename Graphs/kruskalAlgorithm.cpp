#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

class DSU{

    public:
        vector<int> parent, size;
        int total_component;

        DSU(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
            for(int i=0; i<n; i++){
                size[i] = 1;
            }
            total_component = n;
        }

        int get(int x){
            if(x==parent[x]){
                return x;
            }
            else{
                return (parent[x]=get(parent[x]));
            }
        }

        void join(int x, int y){
            int super_parent_x = get(x);
            int super_parent_y = get(y);
            if(super_parent_x != super_parent_y){
                parent[super_parent_x] = super_parent_y;
                size[super_parent_y] += size[super_parent_x];
                size[super_parent_x] = 0;
                total_component--;
            }
        }
};

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for(int i=0; i<m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        edges[i] = {w, x, y};
    }
    sort(edges.begin(), edges.end());
    DSU G(n);
    ll ans=0;
    for(int i=0; i<m; i++){
        int x = edges[i][1];
        int y = edges[i][2];
        int w = edges[i][0];
        if(G.get(x) != G.get(y)){
            G.join(x, y);
            ans += w;
            cout << x+1 << " " << y+1 << " " << w << endl;
            // graph[x].push_back(y);
            // graph[y].push_back(x);
        }
    }
    cout << ans << endl;

    return 0;
}