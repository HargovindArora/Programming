# include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
# define FOR(i, n) for (ll i = 0; i < n; i++)
# define FORI(i, n) for (ll i = 1; i <= n; i++)
#define REP(i, a, b) for(ll i =a; i<=b;i++)
#define RREP(i, a, b) for(ll i =a; i>=b;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
# define all(v) v.begin(), v.end()
# define dbg(x) cout << #x << "=" << x << endl;
# define mp make_pair
#define mod 1000000007
# define pb push_back
# define MAX 2001
#define fi first
#define se second
    
int n, m, l;
vector<long long int > v(MAX);
vector<long long int > w(MAX);
long long int dp[MAX][MAX][6];
    
void solve(){
    FOR(i,n)
    {
        dp[i][0][0]=0;
        dp[0][i][0]=0;
    }

    FORI(i, n)
    FORI(j, m)
    {
    if (v[i-1]==w[j-1])
    {
        dp[i][j][0]=dp[i-1][j-1][0]+1;
    }
    else
        dp[i][j][0]=max(dp[i-1][j][0], dp[i][j-1][0]);
    }
    // cout << dp[n][m][0] << endl;
    
    FORI(i, n)
    FORI(j, m)
    FORI(k, l)
    {
        long long m1 = max(dp[i-1][j][k], dp[i][j-1][k]);
        if (v[i-1]==w[j-1])
            dp[i][j][k]=max(m1,dp[i-1][j-1][k]+1);
        else
            dp[i][j][k]=max(m1, dp[i-1][j-1][k-1]+1);
    }
    cout << dp[n][m][l] << endl;
}
    
int main()
{
    cin>>n >> m >> l;
    FOR(i, n)
        cin >> v[i];
    FOR(i, m)
        cin >> w[i];
    solve();
}

// #include <iostream>
// using namespace std;

// int dp[2005][2005][8];

// int korderedLCS(int *a, int *b, int n, int m, int i, int j, int k) {
//     if(n == i or m == j) {
//         return 0;
//     }
//     if(dp[i][j][k] != -1) {
//         return dp[i][j][k];
//     }
//     int res = 0;
//     if(a[i] == b[j]){
//         res = 1 + korderedLCS(a, b, n, m, i+1, j+1, k);
//     } 
//     else{
//         if(k>0) {
//             res = 1 + korderedLCS(a, b, n, m, i+1, j+1, k-1);
//         }
//         res = max(res, korderedLCS(a, b, n, m, i+1, j, k));
//         res = max(res, korderedLCS(a, b, n, m, i, j+1, k));
//     }
//     dp[i][j][k] = res;
//     return res;
// }

// int main(int argc, char const *argv[])
// {

//     int n, m, k;
//     cin>>n>>m>>k;
//     int a[n];
//     int b[m];
//     for(int i=0;i<n;i++) {
//         cin>>a[i];
//     }
//     for(int i=0;i<m;i++) {
//         cin>>b[i];
//     }
//     for(int i=0;i<2005;i++) {
//         for(int j=0;j<2005;j++) {
//             for(int m=0;m<8;m++) {
//                 dp[i][j][m] = -1;
//             }
//         }
//     }
//     cout<< korderedLCS(a, b, n, m, 0, 0, k);
//     return 0;
// }