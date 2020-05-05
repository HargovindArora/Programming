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

		int n, k;
		cin >> n >> k;
		vector<int> v, w;
		v.reserve(100001);
		w.reserve(100001);
		v.push_back(0);
		w.push_back(0);
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			v.push_back(x);
			w.push_back(x);
		}
		sort(w.begin(), w.end());
		vector<int> a;

		for(int i=1; i<=n; i++){
			if(v[i]!=w[i]){
				a.push_back(i);
			}
		}

		if(a.size()==0){
			cout << 0 << endl;
			continue;
		}

		if((v[a[0]]<v[a[1]] && v[a[1]]>v[a[2]] && v[a[0]]<v[a[2]]) || (v[a[0]]>v[a[1]] && v[a[1]]<v[a[2]] && v[a[0]]<v[a[2]]) || (v[a[0]]>v[a[1]] && v[a[1]]>v[a[2]])){
			cout << -1 << endl;
			continue;
		}
		int count=0;
		for(int i=1; i<=k; i++){

			count=i;
			swap(v[a[0]], v[a[2]]);
			swap(v[a[1]], v[a[2]]);
			if(v==w){
				break;
			}

		}
		if(count<=k){
			for(int i=1; i<=count; i++){
				cout << i << endl;
				cout << a[0] << " " << a[1] << " " << a[2] << endl;
			}
		}
		else{
			cout << -1 << endl;
		}

	}
	
	return 0;
}
