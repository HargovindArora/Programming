#include<iostream>
#include<list>
#include<map>
#define inf 1e9
using namespace std;

class Graph{

    public:
        int v;
        list<pair<int, int>> *adj;

        Graph(int v){
            this->v = v;
            adj = new list<pair<int, int>>[v];
        }

        void addEdge(int u, int v, int w){
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        int findMinVertex(int *weight, bool *visited, int v){

            int minVertex = -1;
            for(int i=0; i<v; i++){
                if(!visited[i] and (minVertex==-1 or weight[i]<weight[minVertex])){
                    minVertex = i;
                }
            }

            return minVertex;
        }
        
        void Prims(){

            bool *visited = new bool[v];
            int *parent = new int[v];
            int *weight = new int[v];
            for(int i=0; i<v; i++){
                visited[i] = false;
                weight[i] = inf;
            }
            parent[0] = -1;
            weight[0] = 0;
            for(int i=0; i<v; i++){
                int minVertex = findMinVertex(weight, visited, v);
                visited[minVertex] = true;
                for(auto neighbour:adj[minVertex]){
                    if(!visited[neighbour.first]){
                        if(weight[neighbour.first]>neighbour.second){
                            parent[neighbour.first] = minVertex;
                            weight[neighbour.first] = neighbour.second;
                        }
                    }
                }
            }
            for(int i=1; i<v; i++){
                cout << i << "-->" << parent[i] << " has weight " << weight[i] << endl;
            }
        }

};

int main(){

    int n, m;
    cin >> n >> m;
    Graph G(n);
    for(int i=0; i<m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        G.addEdge(x, y, w);
    }
    G.Prims();  

    return 0;
}