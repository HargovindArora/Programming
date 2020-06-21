#include<bits/stdc++.h>
#define ll long long int
#define prime 113
using namespace std;

ll initHash(string str, int m){

    ll result = 0;
    for(int i=0; i<m; i++){
        result += (ll)(str[i]*(ll)pow(prime, i));
    }
    return result;
}

ll rollingHash(string str, int oldIndex, int newIndex, ll oldHash, int patLength){

    ll newHash = oldHash-str[oldIndex];
    newHash /= prime;
    newHash += (ll)(str[newIndex]*(ll)pow(prime, patLength-1)); 
    return newHash;
}

bool checkStrings(string str, string pat, int start1, int start2, int end1, int end2){

    if(end1-start1 != end2-start2){
        return false;
    }
    while(start1<=end1 and start2<=end2){
        if(str[start1]!=pat[start2]){
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}

int main(){

    string str, pat;
    cin >> str >> pat;

    ll patHash = initHash(pat, pat.length());
    ll strHash = initHash(str, pat.length());

    for(int i=0; i<=str.length()-pat.length(); i++){
        if(patHash==strHash and checkStrings(str, pat, i, 0, i+pat.length()-1, pat.length()-1)){
            cout << "Matched at " << i << endl;
        }
        if(i<str.length()-pat.length()){
            strHash = rollingHash(str, i, i+pat.length(), strHash, pat.length());
        }
    }

    return 0;
}