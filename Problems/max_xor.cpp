#include<iostream>
using namespace std;

unsigned long long int maximumXOR(unsigned long long int l, unsigned long long int r) {
    unsigned long long int q = l ^ r, a = 1;
    while(q){
        q /= 2;
        a <<= 1;
    }
    return --a;
}

int main () {

	unsigned long long int a, b;
	cin >> a >> b;
	cout << maximumXOR(a,b) << endl;
	return 0;
}