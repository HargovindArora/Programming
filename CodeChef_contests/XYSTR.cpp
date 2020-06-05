#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    string s;
    cin >> s;
    ll pair=0;
    for(int i=0; s[i]!='\0'; i+=2){
        if((s[i]=='x' && s[i+1]=='y') || (s[i]=='y' && s[i+1]=='x')){
            pair++;
        }
        else{
            i--;
        }
    }
    cout << pair << endl;
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