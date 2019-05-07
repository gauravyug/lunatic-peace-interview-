/*
Best Sightseeing Pair
User Accepted: 992
User Tried: 1756
Total Accepted: 1023
Total Submissions: 3436
Difficulty: Medium
Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, and two sightseeing spots i and j have distance j - i between them.

The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.
Example 1:

Input: [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = INT_MIN;
        int prev = A[0];
        for (int i = 1; i < A.size(); i++)
        {
            res = max(res, A[i] - i + prev);
            prev = max (prev, A[i] + i);
        }
        return res;
    }
};