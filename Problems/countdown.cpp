#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;


int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    int q=1;
    while(t--){

        ll n, k;
        cin >> n >> k;
        ll count=0;
        ll temp = k;
        for(int i=0; i<n; i++){
            ll x;
            cin >> x;
            if(x==temp){
                temp--;
                if(temp==0){
                    temp = k;
                    count++;
                }
            }
            else{
                temp = k;
                if(x==temp){
                    temp--;
                }
            }
        }

        cout << "Case #" << q << ": " << count << endl;

        q++;
    }

    return 0;
}