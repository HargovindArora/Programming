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

        int d0, d1;
        ll k;
        cin >> k >> d0 >> d1;
        int d2 = (d0+d1)%10;
        int loop = 2*(d0+d1)%10 + 4*(d0+d1)%10 + 8*(d0+d1)%10 + 6*(d0+d1)%10;
        ll sum = d0 + d1 + d2 + loop*((k-3)/4);
        int left_terms = (k-3)%4;
        if(left_terms==1){
            sum += 2*(d0+d1)%10;
        }
        if(left_terms==2){
            sum += 2*(d0+d1)%10 + 4*(d0+d1)%10
        }
        if(left_terms==3){
            sum += 2*(d0+d1)%10 + 4*(d0+d1)%10 + 8*(d0+d1)%10;
        }
        sum%3==0? cout << "YES" << endl : cout << "NO" << endl;
    }

    return 0;
}