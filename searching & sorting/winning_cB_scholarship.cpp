#include<iostream>
#define ll long long int

using namespace std;


bool canReceive(ll n, ll m, ll x, ll y, ll mid){

    if(mid*x <= m + (n-mid)*y){
        return true;
    }
    else{
        return false;
    }

}


int binaryScholarship(ll n, ll m, ll x, ll y){

    ll s = 0, e = n, mid, ans;

    while(s<=e){

        mid = (s+e)/2;

        if(canReceive(n, m, x, y, mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }

    return ans;
}


int main(){

    ll n, m, x, y;
    cin >> n >> m >> x >> y;

    cout << binaryScholarship(n, m, x, y) << endl;

    return 0;
}