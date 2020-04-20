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

        int laddu = 0;
        int act;
        string org;
        cin >> act >> org;
        while(act--){
            int rank, severity;
            string activity;
            cin >> activity;
            if(activity=="CONTEST_WON"){
                cin >> rank;
                laddu += 300;
                if(rank<20){
                    laddu += (20-rank);
                }
                continue;
            }
            if(activity=="TOP_CONTRIBUTOR"){
                laddu += 300;
                continue;
            }
            if(activity=="BUG_FOUND"){
                cin >> severity;
                laddu += severity;
                continue;
            }
            if(activity=="CONTEST_HOSTED"){
                laddu += 50;
                continue;
            }
        }
        if(org=="INDIAN"){
            cout << laddu/200 << endl;
            continue;
        }
        else{
            cout << laddu/400 << endl;
        }
    }

    return 0;
}