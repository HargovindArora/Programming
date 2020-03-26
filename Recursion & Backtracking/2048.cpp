#include<iostream>
using namespace std;


char spell[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void print(int n){

    if(n==0){
        return;
    }
    print(n/10);
    cout << spell[n%10] << " ";

}


int main(){

    int n;
    cin >> n;

    print(n);

    return 0;
}