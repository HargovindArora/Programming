#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

long long int fastpower(long long int a, ll b){

    if(b==0){
        return 1;
    }
    ll smallAns = (fastpower(a, b/2));
    smallAns = ((smallAns)*(smallAns));

    if(b&1){
        return (a*smallAns);
    }
    else{
        return (smallAns);
    }

}

int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--){

        ll x, y, l, r;
        cin >> x >> y >> l >> r;
        int bits = floor(log2(max(x,y)))+1;
        cout << bits << endl;
        if(l==0 && r>=2*max(x,y)){
            ll ans = fastpower(2, bits)-1;
            cout << ans << endl;
            continue;
        }


    }

    return 0;
}