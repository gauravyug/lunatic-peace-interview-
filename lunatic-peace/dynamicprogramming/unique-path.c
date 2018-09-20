/*
https://leetcode.com/problems/unique-paths-ii/description/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {        
        
        int row = obstacleGridRowSize;
        int col = obstacleGridColSize;
        
        if (obstacleGrid[0][0] != 0)  
            return 0;
        
        if (row == 1 && col == 1) {
            return 1;
        }
        
        int lookup[row][col];// = {0};
    	for (int i = 0; i < row; i++) {
            if (obstacleGrid[i][0] == 0) {
                lookup[i][0] = 1;
                
                if (i>0 && lookup[i-1][0] == 0)
                    lookup[i][0] = 0;
            }
            else 
                lookup[i][0] = 0;
        }

        // Count of paths to reach any cell in first column is 1 
        for (int j = 0; j < col; j++) {
            if (obstacleGrid[0][j] == 0) {
                lookup[0][j] = 1;
                
                if (j > 0 && lookup[0][j-1] == 0)
                    lookup[0][j] = 0;
            }
            else 
                lookup[0][j] = 0;
        }
        
        // Calculate count of paths for other cells in 
        // bottom-up manner using the recursive solution 
        for (int i = 1; i < row; i++) { 
            for (int j = 1; j < col; j++) 
                if (obstacleGrid[i][j] == 0)
                    lookup[i][j] = lookup[i-1][j] + lookup[i][j-1];
                else 
                    lookup[i][j] = 0;

        } 
        
        return lookup[row-1][col-1];
}
