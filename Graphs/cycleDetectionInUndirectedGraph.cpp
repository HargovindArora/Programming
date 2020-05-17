#include<iostream>
#include<list>
#include<map>
using namespace std;

class Graph{

    private:
        list<int> *l;
        int v;

    public:
        Graph(int v){
            this->v = v;
            l = new list<int>[v];
        }

        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }

        bool cycleHelper(int node, bool *visited, int parent){
            visited[node] = true;
            for(auto nbr:l[node]){
                if(!visited[nbr]){
                    bool cycleFound = cycleHelper(nbr, visited, node);
                    if(cycleFound){
                        return true;
                    }
                }
                else if(nbr!=parent){
                    return true;
                }
            }
            return false;
        }

        bool containsCycle(){
            bool *visited = new bool[v];
            for(int i=0; i<v; i++){
                visited[i] = false;
            }
            return cycleHelper(0, visited, -1);
        }

};

int main(){

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    if(g.containsCycle()){
        cout << "Graph contains a cycle\n";
    }
    else{
        cout << "Graph is cycle Mukt\n";
    }

    return 0;
}