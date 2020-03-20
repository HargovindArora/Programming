#include<iostream>
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    
    if(n==1){
        cout << -1 << endl;
        return;
    }
    
    cout << "2";
    int x = n-1;
    while(x--){
        cout << "3";
    }
    cout << endl;
    
    return;
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}