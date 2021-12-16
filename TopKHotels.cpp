/*
Given a list of hotelId, parentHotelId and a score retrieve the top k 
root parentHotelIds with highest scores:

[{0, 1, 10}, {1, 2, 20}, {3, 4, 10}, {7, 8, 5}] K = 2

Result: [[2, 30], [4,10]]

The solution I gave was to create an Object to store scores and the ids, 
then use a Map<CustomObject, CustomObject> from parent to child. 
Then traverse the tree and propagate the sum of scores up to the root note.
*/
#include<iostream>
#include<vector>
#include<queue>
#include <map>
using namespace std;
class Hotel{
  public:
  int hotelId;
  int parenthotelId;
  int rating;
  Hotel(int hotelId,  int rating) {
    this->hotelId = hotelId;
    //this->parenthotelId = parenthotelId;
    this->rating = rating;
  }
};
void dfs(int hotel, int rating, map<int, pair<int, int>>parent, map<int, int> &total) {
        if (!parent.count(hotel)) {
            if (!total.count(hotel))
              total[hotel] += rating;
            
            return;
        }
        pair<int, int> pair = parent[hotel];
        dfs(pair.first, rating + pair.second, parent, total);
        parent[hotel] = {pair.first, 0};
        //parent.put(hotel, new Pair<>(pair.getKey(), 0));
    }
    struct Comparator {
      bool operator() (Hotel const &h1, Hotel const &h2) {
        return h1.rating < h2.rating;
      }
    };
vector<vector<int>> topKDFS(vector<vector<int>> hotels, int k, int n) {
        // map of child_hotel=(parent_hotel, rating)
        map<int, pair<int, int>> parent; 
        for (auto hotel: hotels) {
  
            parent[hotel[0]] = {hotel[1], hotel[2]};
            //parent.put(hotel[0], new Pair<>(hotel[1], hotel[2]));
        }
        map<int, int> total;
        for (auto hotel: hotels) {
            dfs(hotel[0], 0, parent, total);
        }
        for (auto item : total)
        cout << item.first << " " << item.second << endl;
        cout << "hahahahahh" << total.size() << endl;
        vector<vector<int>> ans;// = new ArrayList<>clear();
        //Queue<Integer> pq = new PriorityQueue<>((h1, h2) -> total.get(h1) - total.get(h2));
        //priority_queue<Hotel, vector<Hotel>, Comparator> pq;
        priority_queue<pair<int, int>> pq;
        for(auto e : total ) {
        //for (Map.Entry<Integer, Integer> e: total.entrySet()) {
          //Hotel h(e.first, e.second);
          cout << e.first << " :  " << e.second << endl;
          pq.push({e.second, e.first});
          
        }
        while (!pq.empty() && k > 0) {
            auto hotel = pq.top(); pq.pop();
            vector<int> hp;
            hp.push_back(hotel.second) ;
            hp.push_back(hotel.first);
            ans.push_back(hp);
            k--;
            //ans.add(new int[]{hotel, total.get(hotel)});
        }
        for (auto itr : ans) {
          for (auto i : itr) {
            cout << i << " ";
          }
          cout << endl;
        }
        return ans;
    }
    int main() {
      vector<vector<int>> hotels = {{0,1,10},{1,2,20},{3,4,10},{7,8,5}};
      topKDFS(hotels, 2, 9);
      return 0;
    
    }