#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n;
    cin >> n;

    for(int i=1; i<=n-1; i++){
        cout << " ";
    }
    for(int i=1; i<=n; i++){
        cout << "*";
    }
    cout << endl;
    for(int i=1; i<=n-2; i++){
        for(int j=1; j<=n-i-1; j++){
            cout << " ";
        }
        cout << "*";
        for(int j=1; j<=n-2; j++){
            cout << " ";
        }
        cout << "*";
        cout << endl;
    }
    for(int i=1; i<=n; i++){
        cout << "*";
    }
    
}

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // int t;
    // cin >> t;
    // while(t--){
        
    solve();
        
    // }

    return 0;
}