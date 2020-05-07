#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--){

        ll x, y, l, r;
        cin >> x >> y >> l >> r;
        int bits = floor(log2(max(x,y)))+1;
        if(l==0 && r>=2*max(x,y)){
            ll ans = 2^bits-1;
            cout << ans << endl;
            continue;
        }


    }

    return 0;
}