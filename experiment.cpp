#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
	ll n, count = 0;
  	cin >> n;
  	char ch;
  	for( int i = 0; i < n; i++ ){
    	for( int j = 0; j < n; j++ ){
    	    cin >> ch;
          	if( ch == 'D' ){
            	count++;
            }
        }
    }
  	ll ans = sqrt( count ); // Sqrt of large number will overflow, apna method implement kar sqrt nikaalne ka
  	cout << ans << '\n';
  	return 0;
}