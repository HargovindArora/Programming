#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;

const int MAX_CHAR = 256;

ll distinctSubSeqDP(string s){

    vector<int> last(MAX_CHAR, -1); // (size, intial value)
    int n = s.size();
    ll dp[n+1] = {0};
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = (dp[i-1]*2)%MOD;

        if(last[s[i-1]]!=-1){
            dp[i] = dp[i] = (dp[i] - dp[last[s[i-1]]]+MOD)%MOD;
        }
        last[s[i-1]] = (i-1);
    }
    return (dp[n]);
}

void solve(){

    string s;
    cin >> s;
    cout << distinctSubSeqDP(s) << endl;
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

