#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    int heapSize;
    MaxHeap(vector<int> &nums) {
        heapSize = nums.size();
        buildMaxHeap(nums);
    }
    
private:
    //int heapSize;
     
    int left(int i) { 
        return (i << 1) + 1;
    }
    
    int right(int i) {
        return (i << 1) + 2;
    }
  public:  
    void maxHeapify(vector<int>& nums, int i) {
        int largest = i, l = left(i), r = right(i);
        if (l < heapSize && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest);
        }
    }
    
    void buildMaxHeap(vector<int>& nums) {
        heapSize = nums.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; i--) {
            maxHeapify(nums, i);
        }
    }
};
int findKthLargest(vector<int>& nums, int k) {
        MaxHeap heap(nums);
        int size = heap.heapSize;
        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[--size]);
            heap.maxHeapify(nums, 0);
        }
        return nums[0];
}
int main()
{
    vector <int> arr = {41,15,31,11,19,12,17,10}; 
    cout << findKthLargest(arr, 3) << endl;
    sort(arr.end(), arr.begin());
    //while (arr.size() != 0)
    for (auto x : arr) 
        cout << x << " ";
}