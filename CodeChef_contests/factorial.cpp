#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--){

        ll n;
        cin >> n;
        ll temp = n;
        ll count = 0;
        while(temp>0){
            count = count + temp/5;
            temp = temp/5;
        }
        cout << count << endl;
    }

    return 0;
}