/*  
    @Gaurav YadavCS-11 Asn 2, heap_adt.h
    Purpose: Implements MinHeap class

    @author Gaurav Yadav
    @email gauravyug@gmai.com
    @version 1.1 
    @date 10-Jan-19 
*/
#include<iostream> 
#include<climits> 
using namespace std; 
  
#define N 4 

struct MinHeapNode {
    int element;
    int i; 
    int j;
};
class MinHeap {
    MinHeapNode *harr;
    int heap_size;

    public:
    MinHeap(MinHeapNode a[], int size);

    void MinHeapify(int);

    MinHeapNode extractMin() {
        return harr[0];
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }
    
    int parent(int i) { 
        return (i-1)/2; } 

    void replaceMin(MinHeapNode x) { 
        harr[0] = x;  MinHeapify(0); 
    } 

};


