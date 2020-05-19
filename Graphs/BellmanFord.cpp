#include<iostream>
#define inf 1e9
using namespace std;

class Edge{

    public:
        int src, dest, weight;
};

class Graph{

    public:
        int v, e;
        Edge *edge;

        Graph(int v, int e){
            this->e = e;
            this->v = v;
            edge = new Edge[e];
        }

        void addEdge(int u, int v, int w, int count){
            edge[count].src = u;
            edge[count].dest = v;
            edge[count].weight = w;
        }

        void BellmanFord(int src){
            int distance[v];
            for(int i=0; i<v; i++){
                if(i==src){
                    distance[i] = 0;
                }
                else{
                    distance[i] = inf;
                }
            }
            for(int i=1; i<=v-1; i++){
                for(int j=0; j<e; j++){
                    int src = edge[j].src;
                    int dest = edge[j].dest;
                    int wt = edge[j].weight;
                    if(distance[src]!=inf and distance[src]+wt<distance[dest]){
                        distance[dest] = distance[src]+wt;
                    }
                }
            }
            for(int j=0; j<e; j++){
                int src = edge[j].src;
                int dest = edge[j].dest;
                int wt = edge[j].weight;
                if(distance[src]!=inf and distance[src]+wt<distance[dest]){
                    cout << "Graph has Negative Weight cycle\n";
                    return;
                }
            }
            for(int i=0; i<v; i++){
                cout << i << " - " << distance[i] << endl;
            }
            return;
        }

};

int main(){

    int n, e;
    cin >> n >> e;
    Graph g(n,e);
    for(int i=0; i<e; i++){
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w, i);
    }
    g.BellmanFord(0);

    return 0;
}

