#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
	int t;
	cin >> t;
	while(t--){

		int n, q;
		cin >> n >> q;

		char s[n];
		cin >> s;
		int iso[26]={0};
		for(int i=1; i<=q; i++){
			ll iso[26]={0};
			ll c;
			cin >> c;
			ll count=0;
			int x=0;
			for(int j=0; j<26; j++){
				iso[j]=c;
			}
			if(c==0){
				cout << n << '\n';
				continue;
			}
			for(int j=0; j<n; j++){

				int x=0;
				if(x==26){
					count += (n-j);
				}

				int digit = s[j]-'a';
				iso[digit]--;

			}
			for(int j=0; j<26; j++){

				if(iso[j]<=0){
					count += abs(iso[j]);
				}

			}
			cout << count << '\n';

		}

	}
	
	return 0;
}
