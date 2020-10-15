#include<iostream>
#include<vector>
using namespace std;

class Heap{

    private:
        vector<int> h;
        bool minHeap;

        bool compare(int a, int b){
            if(minHeap){
                return a<b;
            }
            return a>b;
        }

        void heapify(int idx){

            int left = 2*idx;
            int right = left+1;
            int min_idx = idx;
            int last = h.size()-1;
            
            if(left <= last && compare(h[left], h[idx])){
                min_idx = left;
            }
            if(right <= last && compare(h[right], h[min_idx])){
                min_idx = right;
            }

            if(min_idx != idx){
                swap(h[idx], h[min_idx]);
                heapify(min_idx);
            }
        }

    public:
        Heap(int default_size = 100, bool type = true){
            h.reserve(default_size);
            h.push_back(-1); // Dummy value at Index 0
            minHeap = type;
        }

        void push(int d){

            h.push_back(d);
            int idx = h.size()-1;
            int parent = idx/2;

            while(idx>1 and compare(h[idx], h[parent])){

                swap(h[idx], h[parent]);
                idx = parent;
                parent = parent/2;
            }
        }

        int top(){
            return h[1];
        }

        void pop(){
            int last = h.size() - 1;
            swap(h[1], h[last]);
            h.pop_back();
            heapify(1);
        }

        bool empty(){
            return h.size() == 1;
        }
};


int main(){

    Heap h;
    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        h.push(x);
    }

    while(!h.empty()){
        cout << h. top() << " ";
        h.pop();
    }

    return 0;
}