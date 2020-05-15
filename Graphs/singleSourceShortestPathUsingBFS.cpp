#include<iostream>
#include<queue>
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
        void bfs(T src){

            map<T, int> dist;
            queue<T> q;
            q.push(src);
            dist[src] = 0;
            
            while(!q.empty()){

                T node = q.front();
                q.pop();
                for(auto nbr:l[node]){
                    if(!dist[nbr]){
                        q.push(nbr);
                        dist[nbr] = true;
                    }
                }
                cout << node << " ";
            }
            cout << endl;
        }
};

int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);

    return 0;
}