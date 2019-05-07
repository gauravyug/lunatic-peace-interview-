/*
Iterate through the 2D array and use DFS to recursively flip all the connected 1s to 0s. 
We then increment count by 1. 
Floodfill algorithm (https://en.wikipedia.org/wiki/Flood_fill)
Flood-fill (node, target-color, replacement-color):
 1. If target-color is equal to replacement-color
    return.
 2. If the color of node is not equal to target-color 
    return.
 3. Set the color of node to replacement-color.
 4. Perform Flood-fill (one step to the south of node, target-color, replacement-color).
    Perform Flood-fill (one step to the north of node, target-color, replacement-color).
    Perform Flood-fill (one step to the west of node, target-color, replacement-color).
    Perform Flood-fill (one step to the east of node, target-color, replacement-color).
 5. Return.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<int>>& grid) { 
        int count = 0;
            for(int r = 0; r < grid.size(); r++){
                for(int c = 0; c < grid[0].size(); c++){
                    if(grid[r][c] == 1){
                        count++;
                        fill(r, c, grid);
                        eraseIslands(grid, r, c);
                    }
                }
            }
            return count;
    }
    
    void fill(int r, int c, vector<vector<int>>& grid){
   if(grid[r][c] == 1){
            grid[r][c] = 0;
            if(r > 0) 
                fill(r-1, c, grid);
            if(r < grid.size()-1) 
                fill(r+1, c, grid);
            if(c > 0) 
                fill(r, c-1, grid);
            if(c < grid[0].size()-1) 
                fill(r, c+1, grid);
        } else return;
    }
    void eraseIslands(vector<vector<char>>& grid, int i, int j){
         int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};

int main()
{
    vector<vector<int>> matrix;
    matrix = {
        {1,1,0,1,1},
        {0,0,0,0,1},
        {0,1,1,0,0},
    };
    Solution sol;
    cout << sol.numIslands(matrix);
    return 0;
}