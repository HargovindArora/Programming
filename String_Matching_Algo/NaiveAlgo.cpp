#include<iostream>
#include<cstring>
using namespace std;

void NaiveAlgo(string str, string pat){

    for(int i=0; i<=str.size()-pat.size(); i++){
        int j;
        for(j=0; j<pat.size(); j++){
            if(str[i+j]!=pat[j]){
                break;
            }
        }
        if(j==pat.size()){
            cout << "Pattern is found from index " << i << endl;
        }
    }
    return;
}

int main(){

    string str, pat;
    cin >> str >> pat;
    NaiveAlgo(str, pat);

    return 0;
}