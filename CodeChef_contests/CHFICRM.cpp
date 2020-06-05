#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    int a[n];
    int coins[20]={0};
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    if(a[0]!=5){
        cout << "NO" << endl;
        return;
    }
    coins[a[0]]++;
    for(int i=1; i<n; i++){
        if(a[i]==10){
            if(coins[5]>0){
                coins[5]--;
                coins[10]++;
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
        if(a[i]==15){
            if(coins[10]>0){
                coins[10]--;
                coins[15]++;
            }
            else if(coins[5]>1){
                coins[5] -= 2;
                coins[15]++;
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
        if(a[i]==5){
            coins[5]++;
        }
    }
    cout << "YES" << endl;
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