/*Given a stream of rows in the following format, find the cities which has 3 or more hotels with same name
hotelId, hotel Name, City Name*/
#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include<map>
#include<set>
#include<unordered_set>
using namespace std;
class Hotel{
  public:
    string city;
    string hotel_name;
    int hotel_id; 
    Hotel(string city, string name, int id) {
        this->city = city;
        this->hotel_name = name;
        this->hotel_id = id;
    }
};
 //unordered_map<string, Hotel*> hotelCityMap;
 unordered_map<string, unordered_map<string, vector<int>>> hotelCityMap;
 map<pair<int, string>, unordered_map<string,vector<int>>, greater<pair<int, string>>> hotelCityMapNew;
 set<pair<int, string>> hotelMap;
unordered_map<int, string> fmap;
 priority_queue<pair<int, string>> pq;
void topHotelsInCityWithSameName(string city) {
  unordered_set<string> res;
  for (auto m : hotelCityMap) {
    cout << m.first << " :\n" ; 
    for (auto item : m.second) {
      cout << "\t\t" << item.first << " ";
      for (auto itr : item.second) {
         cout << " " << itr << " ";
         }
          cout << endl;
         }
         cout << endl;
  }
    for (auto item : hotelMap) {
      res.insert(item.second);
    }
    for (auto item : res)
    cout << item <<  " " <<  endl;
   
  
}


void addHotel(Hotel *hotel) {
    cout << hotel->hotel_id << endl;
    unordered_map<string, vector<int>> hmap;
    if (hotelCityMap.find(hotel->city) != hotelCityMap.end()) {
        hmap = hotelCityMap[hotel->city];
        hmap[hotel->hotel_name].push_back(hotel->hotel_id);
        fmap[hotel->hotel_id] = hotel->hotel_name;
    }
    else {
      hmap[hotel->hotel_name].push_back(hotel->hotel_id);
    }
  if (hmap[hotel->hotel_name].size() >= 3) {
   
    int n = hmap[hotel->hotel_name].size();
    
    if (hotelMap.count({n-1, hotel->city}) > 0) {
      hotelMap.erase({n-1, hotel->city});
      hotelMap.insert({n, hotel->city});
    }
    else {
      hotelMap.insert({n, hotel->city});
    }
    }
  hotelCityMap[hotel->city] = hmap;
}
int main() {
  vector<Hotel*> hotels;
  hotels.push_back(new Hotel("Bangalore", "Taj", 1));
  hotels.push_back(new Hotel("Bangalore", "Taj", 2));
  hotels.push_back(new Hotel("Bangalore", "Taj", 3));
  hotels.push_back(new Hotel("Bangalore", "Taj", 31));
  hotels.push_back(new Hotel("Bangalore", "Taj", 32));
  hotels.push_back(new Hotel("Bangalore", "Paradise", 4));
  hotels.push_back(new Hotel("Bangalore", "Paradise", 20));
  hotels.push_back(new Hotel("Bangalore", "Paradise", 21));

  hotels.push_back(new Hotel("Bangalore", "Paradise", 41));
  hotels.push_back(new Hotel("Amsterdam", "Paradise", 5));
  hotels.push_back(new Hotel("Amsterdam", "Paradise", 6));
  hotels.push_back(new Hotel("Amsterdam", "Paradise", 61));
  hotels.push_back(new Hotel("Amsterdam", "Richmond", 7));
  hotels.push_back(new Hotel("Amsterdam", "Paradise", 8));
  hotels.push_back(new Hotel("Paris", "Serenity", 9));
  hotels.push_back(new Hotel("Paris", "Paradise", 11));
    hotels.push_back(new Hotel("Paris", "Serenity", 19));
  hotels.push_back(new Hotel("Paris", "Paradise", 91));
    hotels.push_back(new Hotel("Paris", "Serenity", 99));
  hotels.push_back(new Hotel("Paris", "Paradise", 111));
  hotels.push_back(new Hotel("London", "Richmond", 12));
  hotels.push_back(new Hotel("Delhi", "Taj", 13));
  hotels.push_back(new Hotel("London", "Paradise", 143));
  for (auto item : hotels)
    addHotel(item);
  
  topHotelsInCityWithSameName("Bangalore");
  map<pair<int, string>, unordered_map<string,int>, greater<pair<int, string>>> mp;
  unordered_map<string, int> m1;
  m1["A"] = 121;
  m1["A"] = 122;
  m1["B"] = 123;
  mp[{2,"Abs"}] = m1;
  mp[{1,"Ams"}] = m1;
 
  
  return 0;
}