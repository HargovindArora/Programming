#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAX = 100005;

void solve(){

    int n, k;
    cin >> n >> k;
    vector<int> a, b;
    a.reserve(MAX), b.reserve(MAX);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a.push_back(x), b.push_back(x);
    }
    string ans="yes";
    sort(b.begin(), b.end());
    
    
    for(int i=0; i<k; i++){
        vector<int> p,q;
        p.reserve(MAX);
        q.reserve(MAX);
        for(int j=i; j<n; j+=k){

            p.push_back(a[j]);
            q.push_back(b[j]);

        }
        sort(p.begin(), p.end());
        if(p!=q){
            ans = "no";
            break;
        }

    }
    cout << ans << endl;
    return;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}