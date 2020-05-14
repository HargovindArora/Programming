#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

    ll t;
    cin >> t;
    while(t--){

        ll n;
        cin >> n;
        ll c[n], l[n];
        for(ll i=0; i<n; i++){
            cin >> c[i];
        }
        for(ll i=0; i<n; i++){
            cin >> l[i];
        }
        ll minm = c[0];
        ll cost = l[0]*minm;
        for(ll i=1; i<n; i++){
            if(minm>c[i]){
                minm = c[i];
                cost += minm*l[i];
            }
            else{
                cost += l[i]*minm;
            }
        }
        cout << cost << endl;

    }

    return 0;
}