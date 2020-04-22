#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

void maxStrength(ll *arr, ll n, ll k){

    deque<ll> q;
    ll i;
    for(i=0; i<k; i++){
        while(!q.empty() and arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(; i<n; i++){
        cout << arr[q.front()] << " ";
        while(!q.empty() and q.front()<=i-k){
            q.pop_front();
        }
        while(!q.empty() and arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << arr[q.front()] << " " << endl;
}

int main(){

    ll n;
    cin >> n;
    ll *arr = new ll[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    ll k;
    cin >> k;
    maxStrength(arr, n, k);

    return 0;
}