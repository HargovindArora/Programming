#include<iostream>
#include<string>
#include"HashTable.h"
using namespace std;

int main(){

    Hashtable<int> priceMenu;
    priceMenu.insert("Burger", 50);
    priceMenu.insert("Pizza", 100);
    priceMenu.insert("Patty", 20);
    priceMenu.insert("Chowmein", 50);
    priceMenu.insert("Mountain Dew", 40);
    priceMenu.print();
    int *price = priceMenu.search("Burger");
    if(price==NULL){
        cout << "No found " << endl;
    }
    else{
        cout << "Price is " << *price << endl;
    }
    priceMenu["Dosa"] = 60;
    priceMenu["Dosa"] += 10;
    cout << priceMenu["Dosa"] << endl;

    return 0;
}