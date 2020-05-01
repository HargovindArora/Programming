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

        int n;
        cin >> n;
        int a[n];

        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int minm = INT_MAX, maxm = INT_MIN, count=0;
        vector<int> v;
        for(int i=0; i<n; i++){

            if(i==n-1){
                continue;
            }

            if((a[i+1]-a[i])<=2){
                count++;
            }
            else{
                v.push_back(count+1);
                count = 0;
            }
        }
        v.push_back(count+1);
        for(int i=0; i<v.size(); i++){
            minm = min(v[i], minm);
            maxm = max(v[i], maxm);
        }
        cout << minm <<  " " << maxm << endl;

    }
	
	return 0;
}
