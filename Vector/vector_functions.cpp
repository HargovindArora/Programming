#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v{0, 1, 12, 234, 3456, 7890};

    v.push_back(8901);

    v.pop_back(); // Removes last element

    v.insert(v.begin()+2, 4, 100); // Insert elements in the middle

    v.erase(v.begin()+1); //Insert specific element

    v.erase(v.begin()+2, v.end()+5); // Removes a range of element

    cout << v.size() << endl;
    cout << v.capacity() << endl;

    cout << v.front() << endl; //Returns the first element
    cout << v.back() << endl; //Last element of the vector

    v.resize(18); //If the size is increasing then more memory will be allocated
    cout << v.capacity() << endl;

    v.clear(); // remove all the elements, but soes not delete the memory occupied
    cout << v.capacity() << endl; //Capacity remains the same
    cout << v.size() << endl; //Size becomes zero

    if(v.empty()){
        cout << "This is an empty vector" << endl;
    }

    for(int x:v){
        cout << x << " ";
    }
    cout << endl;

    int y;
    cin >> y;
    vector<int> z;
    z.reserve(1000); //Reserve 1000 elements at start


    return 0;
}