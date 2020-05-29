#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {

	string str;
	cin >> str;
	int a[] = {2,3,5,7,11,13,17,19,23,29};

	int count=0;
	for(int i=0; i<4; i++){
		for(int j=0; str[j]!='\0'; j++){
			int digit = str[j]-'0';
			if(digit==a[i]){
				count++;
			}
		}
	}

	int x=str.length(), h=0;
	char ch[1000][100];
	for(int i=0; i<x-1; i++){
		for(int j=i+1; j<x; j++){
			for(int k=i; k<=j; k++){
                ch[h][k] = str[k];
			}
		h++;
		}
	}

	for(int i=0; i<h-1; i++){
		for(int j=0; ch[j]!='\0'; j++){
            cout << ch[h][j];
        }
        cout << endl;
	}


	return 0;
}