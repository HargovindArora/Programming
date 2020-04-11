#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>> x(10);

    for(int i=0; i<20; i++){
        for(int j=0; j<4; j++){
            x[i].push_back(j);
        }
    }

    for(int i=0; i<20; i++){
        for(int j=0; j<4; j++){
            cout << x[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}