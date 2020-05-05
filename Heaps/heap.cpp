#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void upheapify(vector<int> &heap, int idx){

    if(idx==0){
        return;
    }
    int parentIdx = (idx-1)/2;
    if(heap[parentIdx]<heap[idx]){
        swap(heap[parentIdx], heap[idx]);
        upheapify(heap, parentIdx);
    }
    else{
        return;
    }

}

void downHeapify(vector<int> &heap, int idx){
    
    int leftIdx = 2*idx+1;
    int rightIdx = 2*idx+2;
    if(leftIdx >= heap.size() and rightIdx >= heap.size()){
        return;
    }
    int largestIdx = idx;
    if(leftIdx < heap.size() and heap[leftIdx] > heap[largestIdx]){
        largestIdx = leftIdx;
    }
    if(rightIdx < heap.size() and heap[rightIdx] > heap[largestIdx]){
        largestIdx = rightIdx;
    }
    if(largestIdx==idx){
        return;
    }
    swap(heap[idx], heap[largestIdx]);
    downHeapify(heap, largestIdx);
}

void insert(vector<int> &heap, int key){

    heap.push_back(key);
    upheapify(heap, heap.size()-1);

}

void deleteRoot(vector<int> &heap){

    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    downHeapify(heap, 0);

}

void deleteAnyElement(vector<int> &heap, int key){

    int idx;
    for(int i=0; i<heap.size(); i++){
        if(heap[i]==key){
            idx = i;
        }
    }
    heap[idx] = INT_MAX;
    upheapify(heap, idx);
    deleteRoot(heap);

}

void buildHeap(vector<int> &heap){

    for(int i=0; i<heap.size(); i++){
        upheapify(heap, i);
    }

}

void buildHeapOptimized(vector<int> &heap){

    for(int i=(heap.size()-1)/2; i>=0; i--){
        downHeapify(heap, i);
    }

}

void display(vector<int> heap){

    for(auto x:heap){
        cout << x << " ";
    }
    cout << endl;

}

void downHeapifyHelper(vector<int> &heap, int idx, int heapSize){
    
    int leftIdx = 2*idx+1;
    int rightIdx = 2*idx+2;
    if(leftIdx >= heapSize and rightIdx >= heap.size()){
        return;
    }
    int largestIdx = idx;
    if(leftIdx < heapSize and heap[leftIdx] > heap[largestIdx]){
        largestIdx = leftIdx;
    }
    if(rightIdx < heapSize and heap[rightIdx] > heap[largestIdx]){
        largestIdx = rightIdx;
    }
    if(largestIdx==idx){
        return;
    }
    swap(heap[idx], heap[largestIdx]);
    downHeapifyHelper(heap, largestIdx, heapSize);
}

void heapSort(vector<int> &heap){

    int heapSize = heap.size()-1;
    buildHeapOptimized(heap);
    for(int i=heap.size()-1; i>=0; i--){
        swap(heap[0], heap[i]);
        heapSize -= 1;
        downHeapifyHelper(heap, 0, heapSize);
    }

}

int main(){

    vector<int> heap;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        heap.push_back(x);
    }
    // display(heap);
    // deleteRoot(heap);
    // display(heap);
    // int key;
    // cin >> key;
    // deleteAnyElement(heap, key);
    // display(heap);
    heapSort(heap);
    display(heap);

    return 0;
}