#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){

        ll n, q;
        cin >> n >> q;
        ll last_state;
        ll total = 0;
        for(int i=1; i<=q; i++){

            ll a,b;
            cin >> a >> b;
            if(i==1){
                total += abs(0-a);
                total += abs(b-a);
                last_state = b;
                continue;
            }

            total += abs(last_state-a);
            total += abs(a-b);
            last_state = b;

        }
        cout << total << endl;
    }

    return 0;
}