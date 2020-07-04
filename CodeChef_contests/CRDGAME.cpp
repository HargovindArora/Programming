#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    int result;
    int chef=0, morty=0;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        int power1=0, power2=0;
        while(a>0){
            int digit = a%10;
            power1 += digit;
            a /= 10;
        }
        while(b>0){
            int digit = b%10;
            power2 += digit;
            b /= 10;
        }
        if(power1 > power2){
            chef++;
        }
        else if(power1 < power2){
            morty++;
        }
        else if(power1 == power2){
            chef++;
            morty++;
        }
    }

    if(chef>morty){
        cout << 0 << " " << chef << endl;
    }
    else if(chef<morty){
        cout << 1 << " " << morty << endl;
    }
    else{
        cout << 2 << " " << chef << endl;
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