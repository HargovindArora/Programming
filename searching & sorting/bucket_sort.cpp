#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Student{
    public:
        int marks;
        string name;
};

void bucket_sort(Student s[], int n){

    vector<Student> v[101];
    for(int i=0; i<n; i++){
        int m = s[i].marks;
        v[m].push_back(s[i]);
    }
    for(int i=100; i>=0; i--){
        for(vector<Student>::iterator it=v[i].begin(); it!=v[i].end(); it++){
            cout << (*it).marks << " " << (*it).name << endl;
        }
    }

}

int main(){

    Student s[10000];
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i].marks >> s[i].name;
    }
    bucket_sort(s, n);

    return 0;
}