// https://www.hackerrank.com/challenges/even-tree/problem
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

class Graph{

    private:
        unordered_map<int, list<int>> adjList;
    public:
        void addEdge(int u, int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        int findNumberOfChildren(int src, unordered_map<int, list<int>> &directChild, int *freq){

            if(freq[src]==0){
                return 0;
            }
            int ans=0;
            for(auto child:directChild[src]){
                ans += 1+findNumberOfChildren(child, directChild, freq);
            }
            return ans;
        }

        int BFS(int src, int n){

            unordered_map<int, list<int>> directChild;
            unordered_map<int, bool> vis;

            int *freq = new int[n+1];
            for(int i=0; i<n+1; i++){
                freq[i] = 0;
            }

            queue<int> q;
            q.push(src);
            vis[src] = true;

            while(!q.empty()){

                int parent = q.front();
                q.pop();
                for(auto child: adjList[parent]){
                    if(!vis[child]){
                        q.push(child);
                        freq[parent]++;
                        vis[child] = true;
                        directChild[parent].push_back(child);
                    }
                }
            }

            int ans = 0;
            q.push(src);
            while(!q.empty()){

                int parent = q.front();
                q.pop();
                for(auto child: directChild[parent]){
                    q.push(child);
                    // int children = freq[child]+1; // This calculates imediate Children and not all the nodes int hat complete subtree
                    int children = findNumberOfChildren(child, directChild, freq);
                    if(children%2){
                        ans++;
                    }
                }
            }
            return ans;
        }
};

void solve(){
    Graph g;
    int nodes, edges;
    cin >> nodes >> edges;
    for(int i=0; i<edges; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << g.BFS(1, nodes) << endl;
    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();

    return 0;
}