#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> v;

void sumItUp(int arr[], int n, int sum, int i, int j){

    if(sum==0){
        v[j].push_back(arr[i]);
        j++;
        return;
    }
    if(i==n){
        return;
    }
    else if(sum<0){
        return;
    }
    else{
        v[j].push_back(arr[i]);
        sumItUp(arr, n, sum-arr[i], i+1, j);
        v[j].pop_back();
        i=i+1;
        sumItUp(arr, n, sum, i+1, j);
    }
}

int removeDuplicates(int arr[], int n){

	if(n==0||n==1){
		return n;
	}
	int j=0;
	for(int i=0; i<=n-1; i++){
		if(arr[i] != arr[i+1]){
			arr[j++] = arr[i];
		}
	}

	return j;
}

int main() {

	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int sum;
	cin >> sum;

	sort(arr, arr+n);

	n = removeDuplicates(arr, n);

    sumItUp(arr, n, sum, 0, 0);
	
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}