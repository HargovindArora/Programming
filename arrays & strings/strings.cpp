#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool compare(string a, string b){
    return a>b; //Descending order sorting
}

int main(){

    string s1;
    getline(cin, s1);
    cout << s1 << endl;;

    string s[] = {"apple", "shapple", "kela", "vela"};
    sort(s, s+4, compare);


    for(int i=0; i<4; i++){
        cout << s[i] << endl;
    }

    int i;
    for(i=0; i<sizeof(s); i++){
        if(s[i]==s1){
            cout << "String found at index " << i << endl;
            break;
        }
    }
    if(i==sizeof(s)){
        cout << "String doesn't exist" << endl;
    }

    return 0;
}