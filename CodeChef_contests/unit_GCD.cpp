#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int t;
    cin >> t;
    

    while(t--){

        ll n;
        cin >> n;

        if(n==1){
            cout << 1 << '\n';
            cout << 1 << " " << 1 << '\n';
            continue;
        }

        ll x = n/2;
        cout << x << '\n';
        
        for(int i=1; i<n; i+=2){
            if(n%2!=0 && i==1){
                cout << 3 << " " << i << " " << i+1 << " " << n << '\n';
                continue;
            }
            cout << 2 << " " << i << " " << i+1 << '\n'; 
        }
    }

    return 0;
}