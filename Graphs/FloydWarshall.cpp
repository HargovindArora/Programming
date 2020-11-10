#include<iostream>
#include<climits>
#include<vector>

#define INF 10000
using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> graph){

    vector<vector<int>> dist(graph);
    int V = graph[0].size();
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){

                if(dist[i][j] > dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

int main(){

    vector<vector<int>> graph = {
                                    {0, INF, -2, INF},
                                    {4, 0, 3, INF},
                                    {INF, INF, 0, 2},
                                    {INF, -1, INF, 0}
                                };

    auto result = floyd_warshall(graph);
    for(int i=0; i<result; i++){
        for(int j=0; j<result.size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}