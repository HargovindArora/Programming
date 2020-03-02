#include<iostream>
#include<cstring>
using namespace std;

void substrings(char *s){
    int x=strlen(s);
    for(int i=0; i<x; i++){
        for(int j=i; j<x; j++){
            for(int k=i; k<=j; k++){
                cout << s[k];
            }
            cout << endl;
        }
    }

}

int main(){

    char str[100];
    cin >> str;

    substrings(str);

    return 0;
}