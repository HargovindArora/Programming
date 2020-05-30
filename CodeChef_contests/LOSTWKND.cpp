#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

void solve(){

    int a[5], p;
    for(int i=0; i<5; i++){
        cin >> a[i];
    }
    cin >> p;
    ll sum = 0;
    for(int i=0; i<5; i++){
        a[i] = a[i]*p;
        sum += a[i];
    }
    if(120-sum>=0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

}

int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--){

        solve();

    }

    return 0;
}