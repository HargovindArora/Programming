#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m, k;
        cin >> n >> m >> k;
        int mini=INT_MAX, maxi=INT_MIN;
        int c[n][k];
        for(int i=0; i<n; i++){
            for(int j=0; j<k; j++){
                cin >> c[i][j];
                mini = min(mini, c[i][j]);
                maxi = max(maxi, c[i][j]);
            }
        }

        int x = maxi*(maxi+1)/2;
        x = x/maxi;

        for(int i=0; i<n; i++){
            if(i%2==0){
                cout << mini << " ";
            }
            else{
                cout << maxi << " ";
            }
        }
        cout << endl;

    }

    return 0;
}