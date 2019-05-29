/* 724. find pivot index
Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:

Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, i = 0;
        int left_sum = 0;
        for (auto x : nums)
            sum += x;
        cout << sum << endl;
        for( int num : nums ) {
            cout << left_sum * 2 << " sum " << sum << " num " << num << endl;
            if( left_sum * 2 == sum - num )  {
                cout << nums[i];
                return i;
            }
            left_sum += num;
            ++i;
        }
        return -1;
        
    }
};