#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){

    int n;
    cin >> n;
    int x[n], y[n];
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    sort(x, x+n);
    sort(y, y+n);
    int dx = x[0];
    int dy = y[0];

    return 0;
}