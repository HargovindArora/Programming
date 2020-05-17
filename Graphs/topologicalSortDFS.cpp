#include<iostream>
#include<climits>
#include<stack>
#include<list>
#include<map>
using namespace std;

template<typename T>
class Graph{

    private:
        map<T, list<T>> l;

    public:
        void addEdge(T x, T y){
            l[x].push_back(y);
        }

        void dfsHelper(T src, map<T, bool> &visited, list<T> &ordering){

            visited[src] = true;
            for(T nbr: l[src]){
                if(!visited[nbr]){
                    dfsHelper(nbr, visited, ordering);
                }
            }
            ordering.push_front(src);
            return;
        }

        void dfs(){

            map<T, bool> visited;
            list<T> ordering;
            for(auto p:l){
                T node = p.first;
                visited[node] = false;
            }
            for(auto p:l){
                T node = p.first;
                if(!visited[node]){
                    dfsHelper(node, visited, ordering);
                }
            }
            for(auto node:ordering){
                cout << node << " ";
            }
        }
};

int main(){

    Graph<string> g;
    g.addEdge("Python", "ML");
    g.addEdge("Python", "Pytorch");
    g.addEdge("Python", "Data Preprocessing");
    g.addEdge("Pytorch", "Face Detection");
    g.addEdge("ML", "Face Detection");
    g.addEdge("DataSet", "Face Detection");
    g.dfs();

    return 0;
}