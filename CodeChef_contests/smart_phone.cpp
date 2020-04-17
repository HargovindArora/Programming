#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

int main(){

    ll n;
    cin >> n;
    ll a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    ll b[n];
    ll maxm = 0;
    for(int i=0; i<n; i++){
        b[i] = a[i]*(n-i);
        maxm = max(maxm, b[i]);
    }
    cout << maxm << endl;

    return 0;
}