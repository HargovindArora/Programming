#include<iostream>
#define MAX 100005
using namespace std;

int reset[MAX];

void KMPReset(string pat){

    int i=0, j=-1;
    reset[0] = -1;
    while(i<pat.size()){
        while(j>=0 and pat[i]!=pat[j]){
            j = reset[j];
        }
        i++;
        j++;
        reset[i] = j;
    }
    return;
}

void KMPSearch(string str, string pat){

    KMPReset(pat);
    int i=0, j=0;
    while(i<str.size()){
        while(j>=0 and str[i]!=str[j]){
            j = reset[j];
        }
        i++, j++;
        if(j==pat.size()){
            cout << "Matched at " << i-j << endl;
            j = reset[j];
        }
    }
    return;
}

int main(){

    for(int i=0; i<MAX; i++){
        reset[i] = -1;
    }
    string str, pat;
    cin >> str >> pat;
    KMPSearch(str, pat);

    return 0;
}
