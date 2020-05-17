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
            l[y].push_back(x);
        }

        void dfsHelper(T src, map<T, bool> &visited){
            cout << src << " ";
            visited[src] = true;
            for(T nbr:l[src]){
                if(!visited[nbr]){
                    dfsHelper(nbr, visited);
                }
            }
        }

        void dfs(){
            map<T, bool> visited;
            for(auto x:l){
                T node = x.first;
                visited[node] = false;
            }
            int count = 0;
            for(auto x:l){
                T node = x.first;
                if(!visited[node]){
                    cout << "Component " << count << " --> ";
                    dfsHelper(node, visited);
                    count++;
                    cout << endl;
                }
                
            }
        }
};

int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(0,4);
    
    g.addEdge(5,6);
    g.addEdge(6,7);

    g.addEdge(8,8);
    g.dfs();

    return 0;
}