#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

void solve(){

    int n;
    cin >> n;
    int a[n], b[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    int diff[n];
    for(int i=0; i<n; i++){
        diff[i] = a[i]-b[i];
    }
    ll count=0, sum=0;
    for(int i=0; i<n; i++){
        if(diff[i]==0 && sum==0){
            count += a[i];
            continue;
        }
        sum += diff[i];
    }
    cout << count << endl;

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