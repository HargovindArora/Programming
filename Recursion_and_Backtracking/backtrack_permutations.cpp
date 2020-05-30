#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> str;

void permute(char* in, int i){

    if(in[i]=='\0'){
        if(find(str.begin(), str.end(), in) == str.end()){
            str.push_back(in);
        }
        return;
    }

    for(int j=i; in[j]!='\0'; j++){
        swap(in[i], in[j]);
        permute(in, i+1);
        swap(in[i], in[j]);
    }

}


int main(){

    char in[100];
    cin >> in;
    string temp = in;
    permute(in, 0);
    sort(str.begin(), str.end());
    for(int x=0; x<str.size(); x++){
        cout << str[x] << endl;
    }
    return 0;
}