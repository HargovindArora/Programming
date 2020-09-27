#include<iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

string minWindowSubstring(string str, string pat){

    int len1 = str.size();
    int len2 = pat.size();

    if(len1<len2){
        return "No Window";
    }

    int hash_str[256] = {0};
    int hash_pat[256] = {0};
    for(int i=0; i<len2; i++){
        hash_pat[pat[i]]++;
    }

    int start = 0, start_index = -1, min_len = INT_MAX;
    int count = 0;

    for(int j=0; j<len1; j++){
        hash_str[str[j]]++;
        if(hash_pat[str[j]]!=0 and hash_str[str[j]]<=hash_pat[str[j]]){
            count++;
        }
        if(count==len2){
            while(hash_pat[str[start]]==0 or hash_str[str[start]]>hash_pat[str[start]]){
                if(hash_str[str[start]]>hash_pat[str[start]]){
                    hash_str[str[start]]--;
                }
                start++;
            }
            int len_window = j-start+1;
            if(min_len>len_window){
                min_len = len_window;
                start_index = start;
            }
        }
    }

    if(start_index == -1){
        return "No Window";
    }
    return str.substr(start_index, min_len);
}

int main(){

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    string ans = minWindowSubstring(s1, s2);
    cout << ans << endl;
    return 0;
}