#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Car{

    private:
        int price;  

    public:
        int model_no;
        char *name;
        const int tyres;
        // Initialization ists is mandatory for CONST type variables/Data Members
        Car(): name(NULL), tyres(4){
            cout << "This is a default CONSTRUCTOR called everytime when an object is created" << endl;
        }
        // This is a PARAMETRIZED constructor!
        Car(int p, int mn, char *n, int t=4): price(p), tyres(t), model_no(mn) {
            price = p;
            model_no = mn;
            int l = strlen(n);
            name = new char[l+1];
            strcpy(name, n);
        }
        // PERSONALIZED COPY-CONSTRUCTOR
        // DEEP Copy CONSTRUCTOR
        Car(Car &C): tyres(C.tyres) {
            cout << "Copying an object....!" << endl;
            price = C.price;
            model_no = C.model_no;
            name = new char[strlen(C.name)+1];
            strcpy(name, C.name);
        } 
        //OVERIDING DEFAULT COPY ASSIGNMENT OPERATOR - Creates a Deep Copy
        void operator = (const Car &C){
            cout << "In assignment operator"<< endl; 
            cout << "Copying an object....!" << endl;
            price = C.price;
            model_no = C.model_no;
            name = new char[strlen(C.name)+1];
            strcpy(name, C.name);
        }
        void setName(const char *n){
            name = new char[strlen(n)+1];
            strcpy(name, n);
        }

        void start() const{
            cout << "GRR. Starting the car! " << name << endl;
        }
        void setPrice(const int p){
            if(p>1000){
                price = p;
            }
            else{
                price = 1000;
            }
        }
        int getPrice() const{
            return price;
        }
        void print() const{
            cout << name << endl;
            cout << price << endl;
            cout << model_no << endl;
            cout << endl;
        }
        ~Car(){
            cout << "Destroying the car " << name << endl;
            //Code to delete all dynamic data member!
            if(name!=NULL){
                delete [] name;
            }
        }

};

int main(){

    Car C;
    C.model_no = 1001;
    C.setName("Baleno");
    C.setPrice(1500);
    C.print();

    // Car D(100, 69, "HAUDI");
    // D.print();
    // cout << endl;
    // //  Now We will use the default COPY CONSTRUCTOR
    // Car F(D);
    // F.print();
    // cout << endl;
    // Car E(F);
    // E.print();
    // cout << endl;

    Car D(1001, 2001, "BMW");
    
    Car E(10011, 2011, "Audi");
    D = E;
    
    E.name[0] = 'O';
    D.print();
    E.print();
    cout << E.tyres << endl;
    // DEFAULT COPY ASSIGNMENT OPERATOR USES SHALLOW COPY
    // D = E;
    Car *F = new Car(100, 200, "Tesla Car!");
    delete F;

    return 0;
}