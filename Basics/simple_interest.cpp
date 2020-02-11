#include<iostream>

using namespace std;

int main(){

    int p,r,t;
    float si;

    cout << "Enter the values!" << endl;
    cin >> p >> r >> t;

    si = (float)p*r*t/100;

    cout << si << endl;

    return 0;
}