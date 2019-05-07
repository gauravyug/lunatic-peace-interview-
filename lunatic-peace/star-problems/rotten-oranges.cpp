/*
Rotten Oranges.
0 : Empty cell
1 : Cell have fresh oranges
2 : cells have rotten oranges   

Given a 2d array with elements os 0,1,2
   {     0,1,2,3,4
     0  [2,1,0,2,1]
     1  [1,0,1,2,1]
     2  [1,0,0,2,1]
    }
         {2, 1, 0, 2, 1, 2, 1, 0, 2, 1, 1, 0, 0, 2, 1}
  index:  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12, 13,14
    Output : All oranges can be rotten in 2 time frames
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
           int R = grid.size(), C = grid[0].size();

        // queue : all starting cells with rotten oranges
        // fill all oranges in map, here key is code and value is 0, 
        // code is nothing bit the index of item in 2d array.
        queue<int> q;
        map<int, int> depth;
        // Fill the queue with the oranges which are rotten
        for (int r = 0; r < R; ++r) { 
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == 2) {
                    int code = r * C + c; // code is index of an element in matrix.
                    cout << code << endl;
                    q.push(code);
                    depth.insert(pair<int,int>(code, 0)); // 0 days to rot
                }
            }
        }
        // For above input queue consists of 0,3,8,13
        int ans = 0;
        cout << "q.size :" << q.size() << endl;
        while (!q.empty()) {
            int code = q.front();
            q.pop();
            int r = code / C, c = code % C;// with this we will get the index (i,j) of item in matrix.
             cout << "r " << r << "c " << c <<endl; 
            for (int k = 0; k < 4; ++k) { // check all neighbours
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == 1) { // within range and fres orange
                    grid[nr][nc] = 2;
                    int ncode = nr * C + nc;
                    q.push(ncode);
                    depth.insert(pair<int, int>(ncode, depth[code] + 1));
                    ans = depth[ncode];
                }
            }
        }

        for (auto row: grid)
            for (int v: row)
                if (v == 1)
                    return -1;
        return ans;
   
    }
};

int main()
{
    vector<vector<int>> matrix;
    matrix = {
        {2,1,0,2,1},
        {1,0,1,2,1},
        {1,0,0,2,1},
    };
    Solution sol;
    cout << sol.orangesRotting(matrix);
    return 0;

}