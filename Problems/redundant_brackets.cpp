#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


bool solve(string s){

    stack<char> ss;

    for(auto x:s){

        if(x==')'){
            char top = ss.top();
            ss.pop();
            int count=0;
            while(top!='('){
                count++;
                top = ss.top();
                ss.pop();
            }
            if(count < 1){
                return true;
            }
        }
        else{
            ss.push(x);
        }
    }
    return false;
}


int main(){

    int t;
    cin >> t;

    while(t--){

        string s;
        cin >> s;

        bool x = solve(s);
        if(x){
            cout << "Duplicate\n";
        }
        else{
            cout << "Not Duplicate\n";
        }
    }

    return 0;
}