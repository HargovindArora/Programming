#include<bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long int
#define X 1000000007
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){

        ll n, a;
        cin >> n >> a;
        ll power = 0;
        ll sum = 0;
        for(int i=1; i<=n; i++){
            ll y = 2*i-1;
            power = ((ll)pow(a, y))%X;
            sum = (sum + power)%X;
            a = ((power)%X*(a)%X)%X;
            cout << a << " ";
        }

        cout << sum << endl;

    }

    return 0;
}