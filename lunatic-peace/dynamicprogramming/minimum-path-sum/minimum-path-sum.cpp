/*
https://leetcode.com/problems/minimum-path-sum/description/
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int lookup[row][col] = {0};
        
        lookup[0][0] = grid[0][0];
        for (int i = 1; i < row; i++) {
            lookup[i][0] = lookup[i-1][0] + grid[i][0];
        }
       /* for (int i = 0; i < row; i++) {
            printf("%d \t",lookup[i][0]);
        }
        printf("\n");*/
        
        for (int i = 1; i < col; i++) {
            lookup[0][i] =  lookup[0][i-1] + grid[0][i];
        }
        for (int i = 0; i < col; i++) {
            printf("%d \t",lookup[0][i]);
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j< col; j++) {
                if (lookup[i-1][j] < lookup[i][j-1])
                    lookup[i][j] = grid[i][j] + lookup[i-1][j];
                else 
                    lookup[i][j] = grid[i][j] + lookup[i][j-1];
            }
        }
        return lookup[row-1][col-1];
    }
};
