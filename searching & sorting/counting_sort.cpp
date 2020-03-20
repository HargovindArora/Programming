#include<iostream>
#include<algorithm>
#define MAX 1000000
using namespace std;

void countingSort(int a[], int n, int m){

	int c[MAX] = {0}, b[MAX];

	for(int j=0; j<n; j++){
		c[a[j]] = a[j]+1;
	}
	for(int j=1; j<=m; j++){
		c[j] = c[j]+c[j-1];
	}
	for(int j=n-1; j>=0; j--){
		b[c[a[j]]] = a[j];
		c[a[j]] = c[a[j]]-1;
	}
	for(int i=0; i<n; i++){
		cout << b[i] << " ";
	}
	cout << endl;
}

int main() {

	int n;
	cin >> n;
	int a[n];
	int m;

	for(int i=0; i<n; i++){
		cin >> a[i];
		m = max(m, a[i]);
	}

	countingSort(a, n, m);

	return 0;
}