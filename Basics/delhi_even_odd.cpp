#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	while(n--){

		int x;
		cin >> x;
		int sum_odd=0, sum_even=0, d;
		while(x>0){
			d = x%10;
			if(d%2==0){
				sum_even = sum_even+d;
				x = x/10;
				continue;
			}
			else{
				sum_odd = sum_odd+d;
				x = x/10;
			}
			
		}
		if(sum_even%4==0 || sum_odd%3==0){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}

	}

	return 0;
}