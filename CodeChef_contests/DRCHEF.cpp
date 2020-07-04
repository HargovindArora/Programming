#include<bits/stdc++.h>
#define ll long long int
#define endl '\n' 
using namespace std;

void solve(){
    
    int n, x;
    cin >> n >> x;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++){
        int y;
        cin >> y;
        pq.push(y);
    }

    // while(!pq.empty()){
    //     int x = pq.top();
    //     cout << x << " ";
    //     pq.pop();
    // }

    // cout << endl;
    int beg = x;
    ll days = 0;
    while(!pq.empty()){
        int initial = pq.top();
        pq.pop();
        if(x>initial){
            days++;
            x = x - (x-initial);
            x *= 2;
            if(x<beg){
                x = beg;
            }
        }
        else if(x==initial){
            days++;
            x *= 2;
        }
        else{
            while(x<initial){
                x *= 2;
                days++;
            }
            days++;
            x = x - (x-initial);
            x *= 2;
            
        }
    }

    cout << days << endl;

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