#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    if(n%2!=0){
        int x = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << x << " ";
                x++;
            }
            cout << endl;
        }
    }
    else{
        int x = 1;
        for(int i=1; i<=n; i++){
            if(i%2!=0){
                for(int j=1; j<=n; j++){
                    cout << x << " ";
                    x++;
                }
                cout << endl;
            }
            else{
                for(int j=1; j<=n; j++){
                    if(j%2!=0){
                        cout << x+1 << " ";
                    }
                    else{
                        cout << x << " ";
                        x += 2;
                    }
                }
                cout << endl;
            }
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        
        solve();
        
    }

    return 0;
}