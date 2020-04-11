#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class Car{

    public:
        string car_name;
        int x,y;

        Car (){

        }
        Car(string s, int x, int y){
            car_name = s;
            this->x = x;
            this->y = y;
        }
        int distance(){
            return x*x + y*y;
        }
        int length(){
            return car_name.length();
        }

};

bool compare(Car A, Car B){

    int d1 = A.distance();
    int d2 = B.distance();

    if(d1==d2){
        return A.length() < B.length();
    }
    return d1<d2;
}

int main(){

    int n;
    cin >> n;
    vector<Car> v;

    for(int i=0; i<n; i++){
        string name;
        int x,y;
        cin >> name >> x >> y;
        Car temp(name, x, y);
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    for(auto c:v){
        cout << "Car " << c.car_name << " Dist " << c.distance() << " Location " << c.x << ", " << c.y << endl;
    }

    return 0;
}