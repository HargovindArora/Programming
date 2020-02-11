#include<iostream>

using namespace std;

int main(){

    int sum=0, n;
    cin >> n;

    while (n>0)
    {
        int last_digit = n%10;
        sum = sum + last_digit;
        n = n/10;
    }
    
    cout << "Sum of digits is " << sum << endl;

    return 0;
}