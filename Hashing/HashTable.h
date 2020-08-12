#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Node{

    public:

        string key;
        T value;
        Node<T> *next;

        Node(string key, T val){
            this->key = key;
            value = val;
            next = NULL;
        }
        ~Node(){
            if(next!=NULL){
                delete next;
            }
        }
};

template<typename T>
class Hashtable{

    Node<T> **table;
    int current_size;
    int table_size;

    int hashFun(string key){
        int idx = 0;
        int p = 1;
        for(int j=0; j<key.length(); j++){
            idx = idx + (key[j]*p)%table_size;
            idx = idx%table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }

    void rehash(){
        Node<T>** oldTable = table;
        int oldTableSize = table_size;
        table_size = 2*table_size+1;
        table = new Node<T>*[table_size];

        for(int i=0; i<table_size; i++){
            table[i] = NULL;
        }
        current_size = 0;
        for(int i=0; i<oldTableSize; i++){
            Node<T>*temp = oldTable[i];
            while(temp!=NULL){
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }
        delete [] oldTable;
    }

    public:

        Hashtable(int ts=7){
            table_size = ts;
            table = new Node<T>*[table_size];
            current_size = 0;
            for(int i=0; i<table_size; i++){
                table[i] = NULL;
            }
        }

        void insert(string key, T value){
            int idx = hashFun(key);
            Node<T>*n = new Node<T>(key, value);
            n->next = table[idx];
            table[idx] = n;
            current_size++;

            float load_factor = current_size/(1.0*table_size);
            if(load_factor>0.7){
                rehash();
            }
        }

        void print(){
            for(int i=0; i<table_size; i++){
                cout << "Bucket " << i << " -> ";
                Node<T>*temp = table[i];
                while(temp!=NULL){
                    cout << temp->key << "->";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        T *search(string key){
            int idx = hashFun(key);
            Node<T>*temp = table[idx];
            while(temp!=NULL){
                if(temp->key==key){
                    return &temp->value;
                }
                temp = temp->next;
            }
            return NULL;
        }

        T &operator[] (string key){
            T *f = search(key);
            if(f==NULL){
                T garbage;
                insert(key, garbage);
                f = search(key);
            }
            return *f;
        }

        void erase(string key){
            int idx = hashFun(key);
            Node<T> *ptr = table[idx];
            while(ptr!=NULL){
                if(ptr->key==key){
                    break;
                }
                ptr = ptr->next;
            }
            if(ptr==table[idx]){
                table[idx] = ptr->next;
                delete ptr;
            }
            else{
                Node<T> *pre = table[idx];
                while(pre->next!=ptr){
                    pre = pre->next;
                }
                pre->next = ptr->next;
                delete ptr;
            }
        }
};