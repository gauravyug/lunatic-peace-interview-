
/*
Find the top K closest hotels within a price range. In the input grid 0 means a 
blocker which you can't pass through, 1 means road which you can use to navigate, 
any value above 1 is the price of the hotel located at x,y. You will be given this grid, 
price range and origin coordinates. You should return K hotels within price range and 
closest to the given origin.

Input:
[[1,2,0,1],
[1,3,0,1],
[0,2,5,1]
]

Any Idea how to approach this question?
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
void topKHotel(vector<vector<int>> hotels, int x, int y, int k, int price) {
  queue<pair<int, int>> q;
  int m = hotels.size();
  int n = hotels[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  vector<vector<int>> dirs =  {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  q.push({x,y});
  visited[x][y] = true;
  vector<pair<int, int>> result;
  priority_queue<vector<int>> pq;
  while (!q.empty()) {
    auto coord = q.front();
    q.pop();
    int r = coord.first;
    int c = coord.second;
    cout << hotels[r][c] << endl;
    if(hotels[r][c] > 1) {
      
      result.push_back({r,c});
      pq.push({hotels[r][c], r, c});
    }
    for (auto dir : dirs) {
        int xx = dir[0] + r;
        int yy = dir[1] + c;
        cout << xx << " " << yy << endl;
        if (xx < 0 || xx >= m || yy < 0 || yy >= n || visited[xx][yy]) continue;
        q.push({xx,yy});
        visited[xx][yy] = true;
    }

  }
  while (!pq.empty()) {
    vector<int> h = pq.top();
    cout << h[0] << " : " <<h[1] << h[2] << endl;
    pq.pop();
  }
}
int main() {
  vector<vector<int>> hotels = {{1,2,0,1},{1,3,5,1},{0,2,5,1}};
  
  topKHotel(hotels, 1, 3, 2, 7);
  return 0;
}