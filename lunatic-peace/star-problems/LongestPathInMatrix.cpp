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
        vector<vector<int>> visited;
    int LongestPathInMatrix(vector<vector<int>>& grid) { 
        int max_len = 0;
        int ht = grid.size(), wd = grid[0].size();
        visited.resize(ht, vector<int>(wd));
            for(int r = 0; r < grid.size(); r++){
                for(int c = 0; c < grid[0].size(); c++){
                    max_len = max(max_len, floodfill(grid, r, c, INT_MIN));
                }
            }
            return max_len;
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
    int floodfill(vector<vector<int>>& grid, int i, int j, int val){
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n )
            return 0;
        if (grid[i][j] <= val) {
            return 0;
        }
        if (visited[i][j] > 0)
            return visited[i][j];
        
        int r = floodfill(grid, i + 1, j, grid[i][j]);
        int l = floodfill(grid, i - 1, j, grid[i][j]);
        int u = floodfill(grid, i, j + 1, grid[i][j]);
        int d = floodfill(grid, i, j - 1, grid[i][j]);
        visited[i][j] = max(r, max(l, max(u, d))) + 1;
        return visited[i][j];
    }
};



int main()
{
    vector<vector<int>> matrix = {
                                    {9,9,4},
                                    {6,6,8},
                                    {2,1,1}
                                };
    Solution sol;
    cout << sol.LongestPathInMatrix(matrix);
    return 0;
}