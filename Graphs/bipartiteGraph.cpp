#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[100005];
int vis[100005];
bool odd_cycle = 0;

void dfs(int curr, int par, int color){

    vis[curr] = color;
    for(auto child: graph[curr]){
        if(vis[child]==0){
            dfs(child, curr, 3-color);
        }
        else if(child != par && color == vis[child]){
            odd_cycle = 1;
        }
    }
    return;
}

int main(){

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, 0, 1);
    if(odd_cycle){
        cout << "Graph is not Bipartite\n";
    }
    else{
        cout << "Graph is bipartite\n";
    }

    return 0;
}