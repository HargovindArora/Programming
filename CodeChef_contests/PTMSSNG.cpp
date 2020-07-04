#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    int x1=0, y1=0;
    for(int i=0; i<4*n-1; i++){
        int x, y;
        cin >> x >> y;
        x1 ^= x;
        y1 ^= y;
    }
    cout << x1 << " " << y1 << endl;

    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        
        solve();
        
    }

    return 0;
}