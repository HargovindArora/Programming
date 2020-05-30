#include<iostream>
using namespace std;


void inc_dec(int n){
    if(n==0){
        return;
    }
    cout << n << " ";
    inc_dec(n-1);
    cout << n << " ";    

}


int main(){

    int n;
    cin >> n;

    inc_dec(n);

    return 0;
}