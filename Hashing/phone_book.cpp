#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string, vector<string>> phoneBook;

    phoneBook["Aishwary"].push_back("975321");
    phoneBook["Aishwary"].push_back("975322");
    phoneBook["Aishwary"].push_back("975323");
    phoneBook["Aishwary"].push_back("975324");
    phoneBook["Priyam"].push_back("865322");
    phoneBook["Priyam"].push_back("965323");
    phoneBook["Priyam"].push_back("965324");
    phoneBook["Priyam"].push_back("965325");

    for(auto p:phoneBook){
        cout << "Name " << p.first << "->";
        for(string s:p.second){
            cout << s << ",";
        }
        cout << endl;
    }

    string name;
    cin >> name;

    if(phoneBook.count(name)==0){
        cout << "Absent" << endl;
    }
    else{
        for(string s:phoneBook[name]){
            cout << s << ",";
        }
        cout << endl;
    }

    return 0;
}