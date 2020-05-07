#include<iostream>
#include<unordered_map>
using namespace std;

class Student{

    public:

        string firstName;
        string lastName;
        string rollNo;

        Student(string f, string l, string r){
            firstName = f;
            lastName = l;
            rollNo = r;
        }

        bool operator == (const Student &s) const{
            return rollNo==s.rollNo;
        }
};

class HashFunc{

    public:

        size_t operator () (const Student &s) const{
            return s.firstName.length()+s.lastName.length();
        }

};

int main(){

    // Name-Marks
    unordered_map<Student, int, HashFunc> student_map;
    Student s3("Aishwary", "Bhardwaj", "016");
    Student s1("Hargovind", "Arora", "010");
    Student s2("Pranjal", "Vaish", "005");
    Student s4("Priyam", "Omer", "110");
    Student s5("Prashant", "Sikarwar", "021");
    Student s6("Pranjal", "Vaish", "009");

    student_map[s1] = 195;
    student_map[s2] = 194;
    student_map[s3] = 193;
    student_map[s4] = 192;
    student_map[s5] = 191;
    student_map[s6] = 190;

    for(auto s:student_map){
        cout << s.first.firstName << " " << s.first.rollNo << " Marks " << s.second << endl;
    }

    return 0;
}