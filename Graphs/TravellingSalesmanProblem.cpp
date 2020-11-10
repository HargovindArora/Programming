#include<iostream>
#define inf 999999
using namespace std;

int n=4;
int dist[10][10] = {
                    {0, 20, 42, 25},
                    {20, 0, 30, 34},
                    {42, 30, 0, 10},
                    {25, 34, 10, 0}
};
int dp[16][4];

int VISITED_ALL = (1<<n)-1; // Total no. of combination of nodes possible

int tsp(int mask, int location){

    if(mask==VISITED_ALL){
        return dist[location][0];
    }
    if(dp[mask][location]!=-1){
        return dp[mask][location];
    }
    int ans = inf;
    for(int city=0; city<n; city++){
        if((mask&(1<<city))==0){
            int newAns = dist[location][city]+tsp(mask|(1<<city), city);
            ans = min(ans, newAns); 
        }
    }
    return dp[mask][location] = ans;
}

int main(){

    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            dp[i][j] = -1;
        }
    }

    cout << "Min weight Hamiltonian path costs " << tsp(1, 0) << endl;

    return 0;
}
