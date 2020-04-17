#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){

        string s;
        cin >> s;
        int a[26] = {0};
        int x = (s.length())/2;
        int flag=0;
        for(int i=0; i<x; i++){
            a[s[i]-'a']++;
        }
        if((s.length())%2!=0){
            x = x+1;
        }
        for(int i=x; i<s.length(); i++){
            a[s[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(a[i]!=0){
                cout << "NO" << endl;
                flag=1;
                break;
            }
        }
        if(!flag){
            cout << "YES" << endl;
        }
    }

    return 0;
}