#include<iostream>
#include<cmath>
using namespace std;

bool primes[1000000]={false};

void generatePrimes(){
	for(int i=3; i<=1000000; i+=2){
		primes[i]=true;
	}
	primes[0]=primes[1]=false;
	primes[2]=true;
	for(int i=3; i<=sqrt(1000000); i+=2){
		if(primes[i]){
			for(int j=i*i; j*i<=1000000; j+=i){
				primes[j]=false;
			}
		}
	}
}

int main() {

	int n;
	cin >> n;
	generatePrimes();

	// for(int i=0; i<1000000; i++){
	// 	if(primes[i]){
	// 		cout << i << " ";
	// 	}
	// }

	// while(n--){

		// int a,b,count=0;
		// cin >> n;

		for(int i=1; i<=n; i++){
			if(primes[i]){
				cout << i << " ";
			}
		}

		cout <<  endl;
	// }
	// cout << endl;

	return 0;
}
