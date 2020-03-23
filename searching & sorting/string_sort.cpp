#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

bool compare(string s1, string s2){

	if(s1.find(s2) == 0){
		return s1.length() > s2.length();
	}
	else{
		return s1 < s2;
	}
}

int main() {

	int n;
    cin >> n;
	string s[n];

	for(int i=0; i<n; i++){
		cin >> s[i];
	}

	sort(s, s+n, compare);

	for(int i=0; i<n; i++){
		cout << s[i] << endl;
	}

	return 0;
}