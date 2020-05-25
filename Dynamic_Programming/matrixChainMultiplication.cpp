#include<iostream>
#include<cstring>
#include<climits>
#include<vector>
#define ll long long int
using namespace std;

int main(){

    int dp[200][200];
    memset(dp, 0, sizeof(dp));
    vector<int> A = {1, 2, 3, 4, 5, 6, 2, 3, 1};
    int n = A.size()-1;
    for(int i=1; i<n; i++){
        ll r=0, c=i;
        while(c<n){
            int val = INT_MAX;
            for(int pivot=r; pivot<c; pivot++){
                val = min(val, dp[r][pivot]+dp[pivot+1][c]+A[r]*A[pivot+1]*A[c+1]);
            }
            dp[r][c] = val;
            r++, c++;
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}