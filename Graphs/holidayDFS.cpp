#include<iostream>
#include<list>
using namespace std;

class Graph{

    private:
        int v;
        list<pair<int, int>> *l;

    public:
        Graph(int v){
            this->v = v;
            l = new list<pair<int, int>>[v];
        }

        void addEdge(int u, int v, int cost){
            l[u].push_back(make_pair(v,cost));
            l[v].push_back(make_pair(u,cost));
        }

        int dfsHelper(int node, bool *visited, int *count, int &ans){

            visited[node] = true;
            count[node] = 1;
            for(auto nbr_pair:l[node]){
                int nbr = nbr_pair.first;
                int wt = nbr_pair.second;
                if(!visited[nbr]){
                    count[node] += dfsHelper(nbr, visited, count, ans);
                    int nx = count[nbr];
                    int ny = v-nx;
                    ans += 2*min(nx, ny)*wt;
                }
            }
            return count[node];
        }

        int dfs(){

            bool *visited = new bool[v]{false};
            int *count = new int[v]{0};
            int ans = 0;
            dfsHelper(0, visited, count, ans);
            return ans;
        }

};

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Graph g(n);
        cout << g.dfs() << endl;
    }

    return 0;
}