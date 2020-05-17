#include<iostream>
#include<list>
#include<map>
using namespace std;

class Graph{

    private:
        list<int> *l;
        int v;

    public:
        Graph(int x){
            v = x;
            l = new list<int>[v];
        }

        void addEdge(int x, int y){
            l[x].push_back(y);
        }

        bool cycleHelper(int node, bool *visited, bool *stack){

            visited[node] = true;
            stack[node] = true;

            for(int nbr:l[node]){

                if(stack[nbr]==true){
                    return true;
                }
                else if(visited[nbr]==false){
                    bool gotCycle = cycleHelper(nbr, visited, stack);
                    if(gotCycle){
                        return true;
                    }
                }
            }

            stack[node] = false;
            return false;
        }

        bool containsCycle(){

            bool *visited = new bool[v];
            bool *stack = new bool[v];
            for(int i=0; i<v; i++){
                visited[i] = stack[i] = false;
            }
            return cycleHelper(0, visited, stack);
        }
};

int main(){

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2);

    if(g.containsCycle()){
        cout << "Graph Contains a cycle\n";
    }
    else{
        cout << "No cycle present\n";
    }

    return 0;
}