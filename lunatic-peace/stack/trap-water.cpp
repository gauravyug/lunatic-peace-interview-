// C++ program to find maximum amount of water that can
// be trapped within given set of bars.
#include<bits/stdc++.h>
using namespace std;

int findWater(int arr[], int n)
{
	// left[i] contains height of tallest bar to the
	// left of i'th bar including itself
	int left[n];

	// Right [i] contains height of tallest bar to
	// the right of ith bar including itself
	int right[n];

	// Initialize result
	int water = 0;

	// Fill left array
	left[0] = arr[0];
	for (int i = 1; i < n; i++)
	left[i] = max(left[i-1], arr[i]);

	// Fill right array
	right[n-1] = arr[n-1];
	for (int i = n-2; i >= 0; i--)
	right[i] = max(right[i+1], arr[i]);

	// Calculate the accumulated water element by element
	// consider the amount of water on i'th bar, the
	// amount of water accumulated on this particular
	// bar will be equal to min(left[i], right[i]) - arr[i] .
	for (int i = 0; i < n; i++)
	water += min(left[i],right[i]) - arr[i];

	return water;
}
/*Algorithm

1. Initialize ans = 0
2. Iterate the array from left to right:
	a. Initialize max_left=0 and max_right=0
	b. Iterate from the current element to the beginning of array updating:
		max_left=max(max_left,height[j])
	c. Iterate from the current element to the end of array updating:
		max_right=max(max_right,height[j])
	d. Add min(max_left,max_right)−height[i] to \text{ans}ans
	
	Time complexity: O(n^2)
	For each element of array, we iterate the left and right parts
	
*/

int trap(int height[], int n)
{
    int ans = 0;
    int size = n;
    for (int i = 1; i < size - 1; i++) {
        int max_left = 0, max_right = 0;
        for (int j = i; j >= 0; j--) { //Search the left part for max bar size
			//printf("max_left %d height[%d]:%d\n",max_left, j, height[j]);
            max_left = max(max_left, height[j]);
        }
        for (int j = i; j < size; j++) { //Search the right part for max bar size
			//printf("max_right %d height[%d]:%d\n",max_right, j, height[j]);	
            max_right = max(max_right, height[j]);
        }
		printf ("max_left %d, max_right %d, height[%d] %d : \n", max_left, max_right, i, height[i]);
        ans += min(max_left, max_right) - height[i];
    }
    return ans;
}
/*
Find maximum height of bar from the left end upto an index i in the array left_max.
Find maximum height of bar from the right end upto an index i in the array right_max.
Iterate over the \text{height}height array and update ans:
Add min(max_left[i],max_right[i])−height[i] to ansans
*/
int trap_2(int height[], int n)
{
	//if(height == null)
		//return 0;
    int ans = 0;
    int size = n;
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
	//input : {3,0,0,2,0,4};
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
		printf ("%d \t", left_max[i]); // 3,3,3,3,3,4
    }
	printf("\n\n");
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
		printf ("%d \t", right_max[i]);//4,4,4,4,4,4
	}
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;//10
}
// Driver program
int main()
{
	int arr[] = {3,0,0,2,0,4};
	//int arr[] = {3,0,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Maximum water that can be accumulated is "
		<< findWater(arr, n);
		
		cout << "\n naive:: \n Maximum water that can be accumulated is "
		<< trap(arr, n);
		printf("\n\n");
		cout << "\n DP:: \n Maximum water that can be accumulated is "
		<< trap_2(arr, n);
	return 0;
}
