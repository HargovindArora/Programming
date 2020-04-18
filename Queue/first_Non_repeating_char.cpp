#include<iostream>
#include<queue>
#include<unordered_map>
#define endl '\n'
using namespace std;

int main(){

    queue<char> q;
    unordered_map<char, int> m;
    char c;
    cin >> c;
    while(c!='.'){

        q.push(c);
        m[c]++;
        while ((!q.empty())){
            if(m[q.front()]>1){
                q.pop();
            }
            else{
                cout << q.front() << endl;
                break;
            }
        }
        if(q.empty()){
            cout << -1 << endl;
        }
        cin >> c;
    }

    return 0;
}