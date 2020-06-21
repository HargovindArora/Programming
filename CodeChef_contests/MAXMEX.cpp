#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n, m;
    cin >> n >> m;
    int *arr = new int[n+1];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    int count=0;
    for(int i=0; i<n; i++){
        if(arr[i]!=m){
            count++;
        }
        if(arr[i]==m){
            count = 0;
            break;
        }
    }
    if(count==0){
        cout << -1 << endl;
    }
    else{
        cout << count << endl;
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