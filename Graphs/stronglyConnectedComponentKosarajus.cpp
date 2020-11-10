#include<iostream>
#include<cstring>
#include<vector>
#include<list>
#include<map>
using namespace std;

const int n = 100005;
vector<int> gr[n], grr[n];
vector<int> order;
int vis[n], comp[n];

void dfs(int curr){

    vis[curr] = 1;
    for(auto x:gr[curr]){
        if(!vis[x]){
            dfs(x);
        }
    }
    order.push_back(curr);
    return;
}

void dfs_reverse(int curr, int color){
    comp[curr] = color;
    vis[curr] = 1;
    for(auto x:grr[curr]){
        if(!vis[x]){
            dfs_reverse(x, color);
        }
    }
    return;
}

int main(){

    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        grr[y].push_back(x);
    }
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=n ;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    int col = 1;
    memset(vis, 0, sizeof(vis));
    for(int i=n; i>=1; i--){
        if(!vis[order[i]]){
            dfs_reverse(order[i], col);
            col++;
        }
    }
    for(int i=1; i<=n; i++){
        cout << i << " -> " << --comp[i] << '\n';
    }

    return 0;
}

