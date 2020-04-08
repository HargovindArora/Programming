#include<iostream>
#include<list>
#include<vector>
using namespace std;

template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp){
    while(start!=end){
        if(cmp(*start, key)){
            return start;
        }
        start++;
    }
    return end;
}

class Book{

    public:
        string name;
        int price;

        Book(){

        }

        Book(string name, int price){
            this -> name = name;
            this -> price = price;
        }

};

class BookCompare{

    public:
        bool operator () (Book A, Book B){
            if(A.name == B.name){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){

    Book b1("C++", 100);
    Book b2("python", 120);
    Book b3("java", 150);
    Book b4(b1);

    vector<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book bookToFind("C++", 110);

    BookCompare compare;

    // if(compare(b1, bookToFind)){
    //     cout << "True! Same books!" << endl;
    // }
    // else{
    //     cout << "Book not found in the library!" << endl;
    // }
    
    vector<Book>::iterator it = search(l.begin(), l.end(), bookToFind, compare);
    if(it!=l.end()){
        cout << "Book found in the library" << endl;
    }
    else{
        cout << "Book not found!" << endl;
    }

    return 0;
}