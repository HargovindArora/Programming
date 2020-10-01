#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n,m;
    cin >> n >> m;
    string black_row(m, 'B');
    vector<string> result(n, black_row); // Create a String Vector of all Black Rows first
    result[0][0] = 'W';
    for(int i=0; i<n; i++){
        cout << result[i] << endl;
    }

}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
