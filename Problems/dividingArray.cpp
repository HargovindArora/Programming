#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

bool compare(ll a, ll b){
    return a > b;
}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--){

        ll n;
        cin >> n;
        ll arr[n];
        for(ll i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n, compare);
        ll minm=0, maxm=0;
        ll i=0, j=n-1;
        while(i<j){
            maxm += (arr[i]-(arr[j]));
            i++;
            j--;
        }
        for(int i=0; i<n; i+=2){
            minm += (arr[i]-(arr[i+1]));
        }
        cout << minm << " " << maxm << '\n';

    }

    return 0;
}