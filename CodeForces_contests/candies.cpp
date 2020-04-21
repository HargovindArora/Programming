#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){

        ll n;
        cin >> n;
        int i;
        for(i=2; i<=n; i*=2){
            
            if(n%((2*i)-1)==0){
                break;
            }

        }
        cout << n/((2*i)-1) << endl;

    }

    return 0;
}