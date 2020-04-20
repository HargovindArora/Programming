#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main(){

    int q;
    cin >> q;
    stack<int> s;
    while(q--){

        int type;
        cin >> type;
        
        if(type==1){
            
            if(!s.empty()){
                cout << s.top() << endl;
                s.pop();
                continue;
            }
            else{
                cout << "No Code" << endl;
                continue;
            }

        }

        if(type==2){
            int cost;
            cin >> cost;
            s.push(cost);
            continue;
        }

    }

    return 0;
}