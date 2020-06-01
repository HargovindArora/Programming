#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(string a, int n){

    if(n==0){
        return 0;
    }
    int digit = a[n-1] - '0';
    int small_ans = stringToInt(a, n-1);
    return small_ans*10+digit;
}

int main(){

    string s = "1234567";
    int x = s.size();
    int y = stringToInt(s, x);
    cout << y << endl;

    return 0;
}