/*915. Partition Array into Disjoint Intervals
Given an array A, partition it into two (contiguous) subarrays left and right so that:

1. Every element in left is less than or equal to every element in right.
2. left and right are non-empty.
3. left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists

*/
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        
        if (A.size() == 2)
            return 1;
        vector <int> l_max_vec(A.size(), -1);
        vector <int> r_min_vec(A.size(), -1);
        
        int l_max = A[0];
        int r_min = A[A.size() - 1];
        
        for (int i = 0; i < A.size(); i++) {
            l_max = max (A[i], l_max);
            l_max_vec[i] = l_max;
        }
        for (int i = A.size() - 1; i >= 0; i--) {
            r_min = min(A[i], r_min);
            r_min_vec[i] = r_min;
        }   
        
        for (int i = 1; i <A.size() ; i++)
            if (l_max_vec[i-1] <= r_min_vec[i])
                return i;
        return 0;
    }
};
//This solution find the index in O(n), and in single traversal
/*
for input as [37,57,24,19,0,24,49,67,87,87]
max_value : 57 max_value_till_now : 37 A[2] : 24
max_value : 57 max_value_till_now : 57 A[3] : 19
max_value : 57 max_value_till_now : 57 A[4] : 0
max_value : 57 max_value_till_now : 57 A[5] : 24
max_value : 57 max_value_till_now : 57 A[6] : 49
*/
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int max_till_now = A[0];
        int part_Idx = 0; 
        int max_value = max_till_now;
        for (int i = 1; i < A.size(); i++) {
            if (max_till_now > A[i]) {
                max_till_now = max_value;
                part_Idx = i;
            } 
            else {
                max_value = max(max_value, A[i]);
            }
        }
        return part_Idx + 1;    
    }
};
