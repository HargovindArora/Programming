#include<iostream>
using namespace std;

int tilingWays(int n){

    if(n<=3){
        return 1;
    }
    int ans = tilingWays(n-1)+tilingWays(n-4);
    return ans;
}

int main(){

    int n;
    cin >> n;
    cout << tilingWays(n) << endl;

    return 0;
}