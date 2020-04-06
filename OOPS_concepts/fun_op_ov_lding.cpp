#include<bits/stdc++.h>
using namespace std;

class Complex{
    
    int real;
    int img;
    
public:
    Complex(){
        real = 0;
        img = 0;
    }
    Complex(int r, int i){
        real = r;
        img = i;
    }

    void setReal(const int r){
        real = r;
    }
    void setImg(const int i){
        img = i;
    }
    int getReal() const{
        return real;
    }
    int getImg() const{
        return img;
    }
    void print() const{
        if(img>=0){
            cout << real << " + " << img << "i" << endl;
        }
        else{
            cout << real << " - " << abs(img) << "i" << endl;
        }
    }
    void add(const Complex &C){
        real += C.real;
        img += C.img;
    }
    void operator + (const Complex &C){
        real += C.real;
        img += C.img;
    }
    void operator ! (){
        img *= -1;
    }
    int operator [] (string s){
        if(s=="real"){
            return real;
        }
        else{
            return img;
        }
    }

};
//WE USE CIN AND COUT BY REFERENCE BECAUSE THEY ARE SPECIAL FUNCTION OF ISTREAM AND OSTREAM CLASS, 
//AND WE DO NOT WANT TO MAKE A COPY OF THEM
//BY RETURNING THE SAME MEMBERS, IT WILL HELP IN CASCADING OF OPERATORS!
//RETURN AND ACCEPT THEM BY REFERENCE
istream& operator >> (istream& is, Complex &C){

    int r, i;
    is >> r >> i;
    C.setReal(r);
    C.setImg(i);

    return is;
}

ostream& operator << (ostream& os, Complex &C){

    C.print();

    return os;
}

int main(){

    Complex C1(6,3);
    Complex C2;
    C2.setReal(3);
    C2.setImg(6);
    C1.print();
    C2.print();

    C1 + C2;
    C1.print();
    !C1;
    C1.print();

    cout << C1["real"] << endl;
    cout << C2["img"] << endl;

    Complex D1,D2;
    cin >> D1 >> D2;
    cout << D1 << D2;

    return 0;
}