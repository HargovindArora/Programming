#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;
const ll N = 200005;
ll n, q;
vector<ll> adj[N];
ll arr[N];
ll depth[N];
ll parent[N];

void dfs(ll curr, ll prev1=-1, ll depth1=0){

    parent[curr] = prev1;
    depth[curr] = depth1;

    for(ll &x:adj[curr]){
        if(x!=prev1){
            dfs(x, curr, depth1+1);
        }
    }
}

ll solve(ll a, ll b){

    ll freq[105];
    memset(freq, 0, sizeof(freq));
    while(a!=b){

        if(depth[a]>depth[b]){
            freq[arr[a]]++;
            if(freq[arr[a]]>1){
                return 0;
            }
            a = parent[a];
        }
        else{
            freq[arr[b]]++;
            if(freq[arr[b]]>1){
                return 0;
            }
            b = parent[b];
        }
    }
    freq[arr[a]]++;
    if(freq[arr[a]]>1){ // COrner case: When a Becomes equal to b
        return 0;
    }
    ll prev1 = -200;
    ll res = 105;
    for(ll i=1; i<=100; i++){
        if(freq[i]){
            res = min(res, i-prev1);
            prev1 = i;
        }
    }

    return res;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--){

        cin >> n >> q;
        for(ll i=1; i<=n; i++){
            cin >> arr[i];
            adj[i].clear();
        }
        for(ll i=1; i<n; i++){
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1);

        while(q--){

            ll a, b;
            cin >> a >> b;
            cout << solve(a, b) << endl;

        }
    }


    return 0;
}