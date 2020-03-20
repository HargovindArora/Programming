#include<iostream>
#include<algorithm>

#define ll long long int

using namespace std;


bool isPossible(ll a[], ll n, ll k, ll m, ll t){

    int painters = 1;
    ll current_paint = 0;
    for(int i=0; i<n; i++){
        if(a[i]*t+current_paint>m){
            painters++;
            current_paint = (a[i]*t)%10000003;
            if(painters>k){
                return false;
            }
            else{
                current_paint += (a[i]*t)%10000003;
            }
        }
    }

    return true;
}


int binarySearchPaints(ll a[], ll n, ll k, ll t){

    ll sum=0, s=0;
    for(int i=0; i<n; i++){
        sum = sum%10000003 + a[i]%10000003;
        s = max(s, a[i]);
    }
    ll e = sum*t;
    ll ans = s;
    s = s*t;
    while(s<=e){

        ll mid = (s+e)/2;

        if(isPossible(a, n, k, mid, t)){
            ans = mid%10000003;
            e = mid-1;
            continue;
        }
        else{
            s = mid+1;
        }

    }

    return ans%10000003;
}


int main(){

    ll n, k, t;
    cin >> n >> k >> t;
    ll a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    cout << binarySearchPaints(a, n, k, t) << endl;

    return 0;
}