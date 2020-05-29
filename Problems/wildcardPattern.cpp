#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool patternMatchDP(string text, string pattern, ll r, ll c){

     bool dp[r+1][c+1];          //dp[i][j] denotes if the text till i and pattern till j match

    for(int i=0;i<=r;i++){
        dp[i][0] = dp[0][i] = false  ;
    }

    dp[0][0] = true ; //Base case - Strings of 0 length always match

    //If first character of pattern is * then mark (0,1) as true since * can be mapped with empty sequence as well
    if(pattern[0] == '*'){
        dp[0][1] = true ;
    }
    for(int i=0;pattern[i]=='*';i++){
        dp[i][1] = true ; 
    }

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(text[i-1] == pattern[j-1]){
                //If current character of each string matches then mark this as however its previous state was
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[j-1] == '?'){
                //Since ? can be mapped with all characters , do the same for this as well
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[j-1] == '*'){
                //Since * can be mapped with all strings , mark current state as OR of both previous states
                dp[i][j] = dp[i-1][j] || dp[i][j-1] ; 
            }
            else {
                //Since no matching took place , mark this cell as false
                dp[i][j] = false ;
            }
        }
    }


    return dp[r][c];
}

void solve(){

    string text, pattern;
    cin >> text >> pattern;
    ll n = text.size();
    ll m = pattern.size();
    if(patternMatchDP(text, pattern, n, m)){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return;
}

int main(){

    solve();

    return 0;
}