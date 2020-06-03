#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    int a_count=0, b_count=0;
    string s;
    cin >> s;
    bool flag=0;
    int a_rem=n, b_rem=n;
    for(int i=0; i<2*n; i++){
        int x = s[i]-'0';
        if(i%2==0){
            a_rem--;
            if(x==1)
                a_count++;
        }
        else{
            b_rem--;
            if(x==1)
                b_count++;
        }
        
        if((a_count-b_count)>b_rem || (b_count-a_count)>a_rem){
            cout << i+1 << endl;
            break;
        }
        if(a_count==b_count && b_rem==0){
            cout << i+1 << endl;
            break;
        }
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