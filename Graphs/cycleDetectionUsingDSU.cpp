// TO DO
#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

class DSU{

    public:
        vector<int> parent, size;
        int total_component;

        DSU (int n){
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

        int getSuperParent(int x){
            if(x==parent[x]){
                return x;
            }
            else{
                return (parent[x]=getSuperParent(parent[x]));
            }
        }

        void Union(int x, int y){
            int super_parent_x = getSuperParent(x);
            int super_parent_y = getSuperParent(y);
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
    DSU G(n);
    bool cycle=0;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        y--;
        x--;
        if(G.getSuperParent(x)!=G.getSuperParent(y)){
            G.Union(x,y);
        }
        else{
            cycle = 1;
        }
    }
    if(cycle){
        cout << "Cycle in the graph\n";
    }
    else{
        cout << "No Cycle\n";
    }
    

    return 0;
}