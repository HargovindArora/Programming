#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    int s[n+1], p[n+1], v[n+1];
    for(int i=1; i<=n; i++){
        cin >> s[i] >> p[i] >> v[i];
    }
    priority_queue<ll, vector<ll>> pq;
    for(int i=1; i<=n; i++){
        int x = (floor(p[i]/(s[i]+1)))*v[i];
        pq.push(x);
    }
    cout << pq.top() << endl;
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