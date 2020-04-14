#include<iostream>
#include<stack>
#define endl '\n'
using namespace std;

bool checkExpression(string str){

    stack<char> s;
    for(int i=0; i<str.size(); i++){
        char curChar = str[i];
        if(curChar=='('){
            s.push(curChar);
        }
        else if(curChar==')'){
            if(s.empty() || s.top()!='('){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){

    string expr;
    cin >> expr;

    bool isValid = checkExpression(expr);
    cout << isValid << endl;

    return 0;
}