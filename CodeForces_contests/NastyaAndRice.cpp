#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--){

        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        ll low = a-b;
        ll high = a+b;
        ll beg = c-d;
        ll end = c+d;

        ll value1 = low*n;
        ll value2 = high*n;

        if(value1>end || value2<beg){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;

    }

    return 0;
}