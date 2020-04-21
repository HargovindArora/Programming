#include<bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long int
#define X 1000000007
using namespace std;

long long int fastpower(long long int a, ll b){

    if(b==0){
        return 1;
    }
    ll smallAns = (fastpower(a, b/2));
    smallAns = ((smallAns%X)*(smallAns%X))%X;

    if(b&1){
        return (a*smallAns)%X;
    }
    else{
        return (smallAns)%X;
    }

}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){

        ll n, a;
        cin >> n >> a;
        
        ll sum = a;
        ll b = a*a;
        ll power = 1;
        for(int i=2; i<=n; i++){
            ll y = 2*i-1;
            b = ((b%X)*(power%X))%X;
            power = fastpower(b,y)%X;
            sum = (sum%X + power%X)%X;
        }
        

        cout << sum%X << endl;

    }

    return 0;
}