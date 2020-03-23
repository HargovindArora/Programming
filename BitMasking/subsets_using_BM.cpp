#include<iostream>
#include<cstring>
using namespace std;


void filterChars(int n, char a[]){

    int j=0;

    while(n>0){
        int last_bit = (n&1);
        if(last_bit==1){
            cout << a[j];
        }
        j++;
        n=n>>1;
    }
    cout << endl;
}


void range(int n, char a[]){

    for(int i=0; i<(1<<n); i++){
        filterChars(i, a);
    }
}


int main(){

    char a[1001];
    cin >> a;

    int n = strlen(a);
    range(n, a);

    return 0;
}