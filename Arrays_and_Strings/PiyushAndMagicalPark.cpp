#include<iostream>
using namespace std;


void magical_park(char a[][100], int m, int n, int k, int s){

	bool success = true;
	for(int i=0; i<m; i++){

		for(int j=0; j<n; j++){

			char ch = a[i][j];

            if(s<k){
                success = false;
				break;
			}
			if(ch=='*'){
				s += 5;
			}
			else if(ch=='.'){
				s -= 2;
			}
			else{
				break;
			}
			
			if(j!=n-1){
				s--;
			}
		}
	}

	if(success){
		cout << "Yes" << endl;
		cout << s << endl;
	}
	else{
		cout << "No" << endl;
	}

}


int main() {

	int n, m, k, s;
	cin >> n >> m >> k >> s;
	char mat[100][100];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}

	magical_park(mat, n, m, k, s);

	return 0;
}