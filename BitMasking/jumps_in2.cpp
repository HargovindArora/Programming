#include<iostream>
using namespace std;

int main() {

	int t;
	cin >> t;

	while(t--){

		int num;
		cin >> num;

		int bits = __builtin_popcount(num);
		if(bits==1){
			cout << 1 << endl;
			continue;
		}
		
		int count=0;

		while(num>1){
			int mask = 1;
			while(mask<num){
				mask =  mask << 1;
			}
			mask = mask >> 1;
			count++;
			num = num-mask;
		}

		cout << count+1 << endl;

	}

	return 0;
}