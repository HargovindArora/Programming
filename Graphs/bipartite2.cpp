#include<iostream>
#include<vector>
using namespace std;

bool dfsHelper(vector<int> graph[], int node, int parent, int *visited, int color){

    visited[node] = color;
    for(auto nbr:graph[node]){

        if(visited[nbr]==0){
            bool subprob = dfsHelper(graph, nbr, node, visited, 3-color);
            if(subprob==false){
                return false;
            }
        }
        else if(nbr!=parent and color==visited[nbr]){
            return false;
        }
    }

    return true;
}

bool dfs(vector<int> graph[], int N){

    int visited[N] = {0};
    int color = 1;
    bool ans = dfsHelper(graph, 0, -1, visited, color);

    for(int i=0; i<N; i++){
        cout << i << " Color " << visited[i] << endl;
    }

    return ans;
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> graph[n];
    while(m--){
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if(dfs(graph, n)){
        cout << "Bipartite Graph\n";
    }
    else{
        cout << "Not a Bipartite Graph\n";
    }

    return 0;
}