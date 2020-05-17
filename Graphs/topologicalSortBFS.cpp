#include<iostream>
#include<climits>
#include<string>
#include<queue>
#include<list>
#include<map>
using namespace std;

class Graph{

    private:
        list<int> *l;
        int v;

    public:
        Graph(int v){
            l = new list<int>[v];
            this->v = v;
        }

        void addEdge(int x, int y){
            l[x].push_back(y);
        }

        void topologicalSort(){
            int *inDegree = new int[v];
            for(int i=0; i<v; i++){
                inDegree[i] = 0;
            }
            for(int i=0; i<v; i++){
                for(auto y:l[i]){
                    inDegree[y]++;
                }
            }
            //bfs
            queue<int> q;
            for(int i=0; i<v; i++){
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
            while(!q.empty()){
                int node = q.front();
                cout << node << " ";
                q.pop();
                for(auto nbr:l[node]){
                    inDegree[nbr]--;
                    if(inDegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
            cout << endl;
        }

};

int main(){

    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(4,5);

    g.topologicalSort();

    return 0;
}