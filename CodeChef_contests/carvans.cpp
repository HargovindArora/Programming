#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        int minm = a[0];
        int count = 1;
        for(int i=1; i<n; i++){
            if(a[i] <= minm){
                count++;
                minm = min(a[i], minm);
            }
        }
        cout << count << endl;

    }

    return 0;
}