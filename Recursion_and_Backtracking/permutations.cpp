#include<iostream>
#include<set> 
#include<cstring>
using namespace std;


void permute(char* in, int i, set<string> &ss){

    if(in[i]=='\0'){
        string t(in);
        ss.insert(in);
        return;
    }

    for(int j=i; in[j]!='\0'; j++){
        swap(in[i], in[j]);
        permute(in, i+1, ss);
        swap(in[i], in[j]);
    }

}


int main(){

    char in[100];
    cin >> in;
    set<string> s;
    permute(in, 0, s);
    for(auto str:s){
        cout << str << endl;
    }

    return 0;
}