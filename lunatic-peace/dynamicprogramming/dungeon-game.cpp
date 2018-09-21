/*
https://leetcode.com/problems/dungeon-game/description/
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector <int> lookup(col + 1, INT_MAX);
        lookup[col-1] = 1;
      
        for (int i = row-1; i >=0; i--) {
            for (int j = col-1; j >=0; j--) {
                //printf ("lookup[%d]:%d lookup[%d]:%d dungeon[%d][%d]:%d", j, lookup[j], j +1, lookup[j+1], i, j, dungeon[i][j]);
                lookup[j] = getMin (min(lookup[j], lookup[j+1]) - dungeon[i][j]);
                //printf ("\n");
            }
            /*for (int k = 0; k <=col; k++)
                printf ("%d\t", lookup[k]);
            printf ("\n");*/
        }
        
        return lookup[0]; 
    }
    
    int getMin(int n) {
        return n <=0 ? 1: n;
    }
};
