#include<iostream>
#include<list>

using namespace std;

class Graph{

    private:
        int V;
        list<pair<int, int>> l; // Edge List Representation

    public:
        Graph(int V){
            this->V = V;
        }

        void addEdge(int u, int v){
            l.push_back(make_pair(u, v));
        }

        int findSet(int i, int parent[]){
            if(parent[i]==-1) return i;

            // return findSet(parent[i], parent);
            return parent[i] = findSet(parent[i], parent); // Path Compression Optimisation
        }

        void union_set(int x, int y, int parent[], int rank[]){

            int s1 = findSet(x, parent);
            int s2 = findSet(y, parent);

            // if(s1!=s2){
            //     parent[s1] = s2;
            // }

            // Union By Rank
            if(s1 != s2){
                if(rank[s1]<rank[s2]){
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                }
                else{
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }
            }
        }

        bool contains_cycle(){

            int *parent = new int[V];
            int *rank = new int[V];

            for(int i=0; i<V; i++){
                parent[i] = -1;
                rank[i] = 1;
            }

            for(auto edge: l){
                int i = edge.first;
                int j = edge.second;

                int s1 = findSet(i, parent);
                int s2 = findSet(j, parent);

                if(s1!=s2){
                    union_set(s1, s2, parent, rank);
                }
                else return true;
            }
            delete []parent; 

            return false;
        }

        int pairing(){

            int *parent = new int[V];
            int *rank = new int[V];

            for(int i=0; i<V; i++){
                parent[i] = -1;
                rank[i] = 1;
            }

            int ans = 0;
            for(auto edge: l){
                int i = edge.first;
                int j = edge.second;

                int s1 = findSet(i, parent);
                int s2 = findSet(j, parent);

                union_set(s1, s2, parent, rank);
            }

            for(int i=0; i<V; i++){
                ans += V - rank[findSet(i, parent)];
            }

            delete [] parent;
            delete [] rank;

            return ans/2;
        }
};


int main(){

    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    if(g.contains_cycle()){
        cout << "Cycle present" << endl;
    }
    else cout << "No cycle" << endl;

    return 0;
}