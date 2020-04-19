#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--){

        int g;
        cin >> g;
        while(g--){
            
            ll i, n, q;
            cin >> i >> n >> q;
            if(n%2==0){
                cout << n/2 << endl;
                continue;
            }
            else{
                if(i==1){
                    if(q==1){
                        cout << n/2 << endl;
                        continue;
                    }
                    else{
                        cout << n/2 + 1 << endl;
                        continue;
                    }
                }
                else{
                    if(q==1){
                        cout << n/2 + 1 << endl;
                        continue;
                    }
                    else{
                        cout << n/2 << endl;
                        continue;
                    }
                }
            }
        }
    }

    return 0;
}