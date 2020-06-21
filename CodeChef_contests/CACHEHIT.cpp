#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n, b, m;
    cin >> n >> b >> m;
    int j=0;
    int count=0;
    int a[n+1];
    a[0] = 0;
    for(int i=1; i<n; i++){
        if(i%b==0){
            j++;
        }
        a[i] = j;
        
    }
    int x;
    cin >> x;
    int cache = a[x];
    count++;
    for(int i=1; i<m; i++){
        cin >> x;
        if(cache!=a[x]){
            count++;
            cache = a[x];
        }
    }
    cout << count << endl;
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