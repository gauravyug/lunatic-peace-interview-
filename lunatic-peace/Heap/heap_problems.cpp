#include "heap_adt.cpp"
#define N 4
void printMatrixInSortedOrder(int mat[][N])
{
    MinHeapNode *harr = new MinHeapNode[N];
    for (int i = 0; i < N; i++) {
        harr->element = mat[i][0];
        harr->i = i; // row index
        harr->j = 1; // index of next elemnt to be picked
    
    }
    MinHeap heap(harr, N);
    for (int idx = 0; idx < N*N; idx++ )  {
        MinHeapNode node = heap.extractMin();
        cout << node.element << " ";

        // Find the next elelement that will replace current 
        // root of heap. The next element belongs to same 
        // array as the current root. 
        
        if (node.j < N) {
            node.element = mat[node.i][node.j];
            node.j += 1; 
        } 
        else {
            node.element = INT_MAX;
        }
        heap.replaceMin(node);
    }
}

int main()
{ 
    int mat[N][N] = { {10, 20, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {27, 29, 37, 48}, 
                    {32, 33, 39, 50}, 
                  }; 
  printMatrixInSortedOrder(mat); 
  return 0; 
}