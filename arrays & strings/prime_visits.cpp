#include<iostream>
#include<cmath>
using namespace std;

bool primes[1000000];

void generatePrimes(){
	for(int i=3; i<=1000000; i+=2){
		primes[i]=true;
	}
	primes[0]=primes[1]=false;
	primes[2]=true;
	for(int i=2; i<=sqrt(1000000); i++){
		if(primes[i]){
			for(int j=i; j*i<=1000000; j++){
				primes[i*j]=false;
			}
		}
	}
}

int main() {

	int n;
	cin >> n;
	generatePrimes();

	while(n--){

		int a,b,count=0;
		cin >> a >> b;

		for(int i=a; i<=b; i++){
			if(primes[i]){
				count++;
			}
		}

		cout << count << endl;
	}

	return 0;
}