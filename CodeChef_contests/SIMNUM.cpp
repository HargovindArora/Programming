#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

void solve(){

    string s;
    cin >> s;
    string a = s;
    ll ans = s.size();
    for(int i=1; a[i]!='\0'; i++){
        
        int x=i;
        for(int j=0; s[j]!='\0'; j++){
            if(a[x]==s[j]){
                ans++;
                x++;
            }
            else{
                break;
            }
        }


    }
    cout << ans << endl;
}

int main() {
	
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