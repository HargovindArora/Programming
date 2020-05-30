#include<iostream>
#include<string>
#include<vector>
using namespace std;


char keypad[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string searchIn[] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak", "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

vector<string> keys;

void printKeypadString(char *in, char *out, int i, int j){

    if(in[i]=='\0'){
        out[j] = '\0';
        keys.push_back(out);
        return;
    }

    int digit = in[i] - '0';
    if(digit==1||digit==0){
        printKeypadString(in, out, i+1, j);
    }

    for(int k=0; keypad[digit][k]!='\0'; k++){
        out[j] = keypad[digit][k];
        printKeypadString(in, out, i+1, j+1);
    }

}


int main(){

    char in[100];
    char out[100];
    cin >> in;

    printKeypadString(in, out, 0, 0);

	int x = keys.size(), y = 11;

	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			if(searchIn[j].find(keys[i])!=string::npos){
				cout << searchIn[j] << endl;
			}
		}
	}

    return 0;
}