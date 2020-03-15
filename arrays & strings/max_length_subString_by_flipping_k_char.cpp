#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int findLen(string& A, int n, int k, char ch) 
{ 
    int maxlen = 1; 
    int cnt = 0; 
    int l = 0, r = 0; 
    while (r < n) { 
        if (A[r] != ch) 
            ++cnt; 
  
        while (cnt > k) { 
            if (A[l] != ch) 
                --cnt; 
            ++l; 
        } 
        maxlen = max(maxlen, r - l + 1); 
        ++r; 
    } 
    return maxlen; 
} 
int answer(string& A, int n, int k) 
{ 
    int maxlen = 1; 
    for (int i = 0; i < 26; ++i) { 
        maxlen = max(maxlen, findLen(A, n, k, i+'a')); 
    } 
    return maxlen; 
}


int main() {

	int k;
	cin >> k;
	string str;
	cin >> str;
	int n = str.length();
	cout << answer(str, n, k) << endl;

	return 0;
}