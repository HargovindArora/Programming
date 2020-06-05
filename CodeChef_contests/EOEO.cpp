#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    ll ts;
    cin >> ts;
    if(ts%2!=0){
        cout << (ll)ts/2 << endl;
        return;
    }
    while(1){

        if(ts%2==0){
            ts = ts/2;
        }
        else{
            cout << (ll)ts/2 << endl;
            return;
        }
    }
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