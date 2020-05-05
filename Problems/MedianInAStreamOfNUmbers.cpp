#include <bits/stdc++.h>
using namespace std;
int main() {
    int testCases ; 
    cin >> testCases ; 
    while(testCases--){
        long n ;
        long median ;
        priority_queue<long , vector<long> , greater<long>> minHeap ; 
        priority_queue<long> maxHeap ; 
        int minSize = 0 ;
        int maxSize = 0 ;
        int size ;
        cin >> size ;

        median = 0;
        while(size--){

            cin >> n;

            if(n < median){
                maxHeap.push(n);
                maxSize ++ ; 
            }
            else {
                minHeap.push(n);
                minSize ++ ; 
            }
            if(abs(minSize - maxSize) == 2){
                //Imbalance
                if(minSize > maxSize){
                    long temp = minHeap.top() ; 
                    minHeap.pop() ; 
                    minSize -- ;
                    maxHeap.push(temp);
                    maxSize ++ ; 
                }
                else {
                    long temp = maxHeap.top();
                    maxHeap.pop(); 
                    maxSize--;
                    minHeap.push(temp);
                    minSize++;
                }
            }

            //Recalculate median after every iteration
            if(minSize == maxSize){
                median = ( minHeap.top() + maxHeap.top() )/ 2 ;
            }
            else if(minSize > maxSize){
                median = minHeap.top() ;
            }
            else {
                median = maxHeap.top() ;
            }

            cout << median << " ";
        }
        cout << endl;
    }


    return 0;    
}