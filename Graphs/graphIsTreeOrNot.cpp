#include<iostream>
#include<climits>
#include<string>
#include<queue>
#include<list>
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
            //undirected Graph
            l[x].push_back(y);
            l[y].push_back(x);
        }

        bool isTree(){

            bool *visited = new bool[v];
            int *parent = new int[v];
            queue<int> q;
            for(int i=0; i<v; i++){
                visited[i] = false;
                parent[i] = i;
            }
            // bfs
            int src = 0;
            q.push(src);
            visited[src] = true;
            while(!q.empty()){

                int node = q.front();
                q.pop();
                for(int nbr:l[node]){
                    if(visited[nbr] and parent[node]!=nbr){
                        return false;
                    }
                    else if(!visited[nbr]){
                        visited[nbr] = true;
                        parent[nbr] = node;
                        q.push(nbr);
                    }
                }

            }
            return true;
        }
};

int main(){

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(3,2);
    g.addEdge(1,2);
    // g.addEdge(0,3);
    if(g.isTree()){
        cout << "It is a tree\n";
    }
    else{
        cout << "Not a tree\n";
    }

    return 0;
}