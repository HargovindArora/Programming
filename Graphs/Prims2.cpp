#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Graph{

    vector<pair<int, int>> *l;
    int V;

    public:

        Graph(int n){
            V = n;
            l = new vector<pair<int, int>> [n];
        }

        void addEdge(int x, int y, int w){
            l[x].push_back({y, x});
            l[y].push_back({x,w});
        }

        int prims(){

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
            
            bool *visited = new bool[V]{0};
            int result = 0;

            Q.push({0, 0});

            while(!Q.empty()){

                auto best = Q.top();
                Q.pop();

                int to = best.second;
                int weight = best.first;

                if(visited[to]) continue;

                result += weight;
                visited[to] = true;

                for(auto x:l[to]){
                    
                    if(visited[x.first]==0){
                        Q.push({x.second, x.first});
                    }
                }
            }

            return result;
        }
};


int main(){

    int n,m;
    cin >> n >> m;
    Graph g(n);

    for(int i=0; i<m; i++){
        int x,y,w;
        cin >> x >> y >> w;
        g.addEdge(x-1, y-1, w);
    }

    cout << g.prims() << endl;

    return 0;
}