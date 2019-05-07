#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> nums, int k) {
        vector <double> res;
        if (nums.size() == 0)
            return res;
        /*for (int i =0; i < nums.size(); i++) 
        cout << nums[i];*/
        int count = 0;
        bool flag = false;
        deque <int> temp; //vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (count < k) {
                 temp.push_back(nums[i]);
            }
            if (temp.size() == k) {
                for (int i =0; i < temp.size(); i++) 
                     cout << temp[i] << " ";
                double cal = findMedian(temp, temp.size());
                cout << "\n" << cal << endl;
                res.push_back(cal);
                temp.pop_front();
                count = 0;
                flag = true;
            }
            if (!flag)
                count = count + 1;
            if (count == 0)
                flag = false;
        }
        return res;
    }
    double findMedian(deque<int> a, int n) 
    { 
        // First we sort the array 
        sort(a.begin(), a.end()); 
        
        // check for even case 
        if (n % 2 != 0) 
           return (double)a[n/2]; 
        return (double)(a[(n-1)/2] + a[n/2])/2.0; 
    } 
};


int main()
{
    Solution sol;
    vector<int> arr; //[1,3,-1,-3,5,3,6,7] 3
    vector <double> res;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(-1);
    arr.push_back(-3);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(7);
    
    res = sol.medianSlidingWindow(arr, 3);
    for (int i =0; i < res.size(); i++) 
        cout << res[i];
    
    return 0;
}

quickselect(l, k, pivot_fn):
    """
    Select the kth element in l (0 based)
    :param l: List of numerics
    :param k: Index
    :param pivot_fn: Function to choose a pivot, defaults to random.choice
    :return: The kth element of l
    """
    if len(l) == 1:
        assert k == 0
        return l[0]

    pivot = pivot_fn(l)

    lows = [el for el in l if el < pivot]
    highs = [el for el in l if el > pivot]
    pivots = [el for el in l if el == pivot]

    if k < len(lows):
        return quickselect(lows, k, pivot_fn)
    elif k < len(lows) + len(pivots):
        # We got lucky and guessed the median
        return pivots[0]
    else:
        return quickselect(highs, k - len(lows) - len(pivots), pivot_fn)
}