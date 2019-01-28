#include "heap_adt.h"

MinHeap::MinHeap(MinHeapNode a[], int size) 
{
    heap_size = size;
    harr = a;
    int i = (heap_size -1 / 2);
    while ( i>=0 ) {
        MinHeapify(i);
        i--;
    }
}

void MinHeap::MinHeapify(int i)
{
    int l_child = left(i);
    int r_child = right(i);

    int min = i;

    if (l_child < heap_size && harr[l_child].element < harr[i].element)
        min = l_child;
    if (r_child < heap_size && harr[r_child].element < harr[min].element)
        min = r_child;
    if (min != i) {
        swap(harr[min], harr[i]);   
        MinHeapify(min);
    }
}