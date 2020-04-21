#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main(){

    string s;
    cin >> s;

    stack<char> bracks;
    for(int i=0; i<s.length(); i++){

        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            bracks.push(s[i]);
            continue;
        }
        if(bracks.empty() && (s[i]==')' || s[i]=='}' || s[i]==']')){
            cout << "No" << endl;
            return 0;
        }
        if(s[i]==')'){
            if(bracks.top()=='('){
                bracks.pop();
                continue;
            }
            else{
                cout << "No" << endl;
                return 0;
            }
        }
        if(s[i]=='}'){
            if(bracks.top()=='{'){
                bracks.pop();
                continue;
            }
            else{
                cout << "No" << endl;
                return 0;
            }
        }
        if(s[i]==']'){
            if(bracks.top()=='['){
                bracks.pop();
                continue;
            }
            else{
                cout << "No" << endl;
                return 0;
            }
        }

    }

    if(bracks.empty()){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }


    return 0;
}