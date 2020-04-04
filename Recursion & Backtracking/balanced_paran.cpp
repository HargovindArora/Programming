#include<iostream>
using namespace std;

void printParanthesis(int x, int n, int i, int j, char str[1000]){

	if(j==n){
        str[x] = '\0';
		cout << str << endl;
		return;
	}
	else{
		if(i>j){
			str[x] = ')';
			printParanthesis(x+1, n, i, j+1, str);
		}
		if(i<n){
			str[x] = '(';
			printParanthesis(x+1, n, i+1, j, str);
		}
	}
}

int main() {

	int n;
	cin >> n;
    char str[1000];
	printParanthesis(0, n, 0, 0, str);

	return 0;
}