#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void dfs(vector<int> graph[], int i, bool *visited, vector<int> &stack){

    visited[i] = true;
    for(auto nbr:graph[i]){
        if(!visited[nbr]){
            dfs(graph, nbr, visited, stack);
        }
    }

    stack.push_back(i);
}

void dfs2(vector<int> rev_graph[], int i, bool *visited){

    visited[i] = true;
    cout << i << " ";
    for(auto nbr:rev_graph[i]){
        if(!visited[nbr]){
            dfs2(rev_graph, nbr, visited);
        }
    }
}

void solve(vector<int> graph[], vector<int> rev_graph[], int n){

    bool visited[n];
    memset(visited, 0, n);

    vector<int> stack;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(graph, i, visited, stack);
        }
    }

    memset(visited, 0, n);
    char component = 'A';
    for(int x=stack.size()-1; x>=0; x--){
        int node = stack[x];
        if(!visited[node]){
            cout << "Component " << component << " -> ";
            dfs2(rev_graph, node, visited);
            cout << endl;
            component++;
        }
    }

}

int main(){

    int n;
    cin >> n;

    vector<int> graph[n];
    vector<int> rev_graph[n];

    int m;
    cin >> m;

    while(m--){

        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }

    solve(graph, rev_graph, n);

    return 0;
}