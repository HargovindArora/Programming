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

        int n, m;
        cin >> n >> m;

        int a[n+1];
        int x[n+1];
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }

        if(m==0){

            pair<int, int> arr[n+1];
            for(int i=1; i<=n; i++){
                arr[i].first = a[i];
                arr[i].second = i;
            }
            sort(arr+1, arr+n+1);
            vector<bool> v(n+1, false);

            int ans = 0;

            for(int i=1; i<=n; i++){

                if(v[i] || arr[i].second==i){
                    continue;
                }
                int cycle_size = 0;
                int j = i;
                while(!v[j]){

                    v[j] = 1;
                    j = arr[j].second;
                    cycle_size++;

                }
                if(cycle_size>0){
                    ans += cycle_size-1;
                }
            }
            cout << ans << endl;
            continue;
        }

        int b[n+1];
        for(int i=1; i<=m; i++){
            cin >> b[i];
        }
        


    }
	
	return 0;
}
