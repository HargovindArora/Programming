#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

void solve(){

    ll n;
    cin >> n;
    ll ans = (n*(n+1))/2;
    if(n%2==0){
        ans = ans-(n/2);
    }
    cout << ans << endl;
}

int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}