#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
using namespace std;


class Ticket {
  public:
  int date;
  string to;
  string from;
  int price;
  Ticket(int date, string source, string destination, int price) {
    this->date = date;
    this->to = source;
    this->from = destination;
    this->price = price;
  }
};
class  Itinerary {
  public:
    vector<string> order;
    int cost;
    Itinerary(vector<string> order, int cost) {
        this->order = order;
        this->cost = cost;
    }
};
Itinerary *best;

class City{
  public:
   string name;
   int costOfStay;
   City(string name, int price) {
     this->name = name;
     costOfStay = price;
   }
};
unordered_map<string, unordered_map<string, Ticket*>> graph;
unordered_map<string, City* > priceMap;


void getLongestIternary(string from, int cost, int prevDate, int budget, set<Ticket*> &used, vector<string> &order) {
    if (cost > budget) {
      cout << "cost exceeds" << endl;
      return;
    }
    order.push_back(from);

    if (order.size() > 1 && order[0] == order[order.size()-1]) {
       if (order.size() > best->order.size() || (order.size() == best->order.size() && cost < best->cost)) {
         best = new Itinerary(order, cost );
         order.pop_back();
         return;
       }
    }
   
    for (auto ticket : graph[from]) {
          
        if (used.find(ticket.second) == used.end() && ticket.second->date > prevDate) {
                used.insert(ticket.second);
                int hotelCost = 0;
               // cout << ticket.second->from  << " : "<< ticket.second->to << " : " << ticket.second->price<<endl;
                if (prevDate > 0)
                    hotelCost = (ticket.second->date - prevDate) * priceMap[from]->costOfStay;
                getLongestIternary(ticket.first, cost + ticket.second->price + hotelCost,ticket.second->date,  budget, used, order);
                cost = cost - hotelCost;
                used.erase(ticket.second);
              
            }
            
    }     
  }
 
  


int main() {
 
  City *c1 = new City("Amsterdam", 400);
  City *c2 = new City("London", 300);
  City *c3 = new City("Paris", 500);
  priceMap["Amsterdam"] = c1;
  priceMap["London"] = c2;
  priceMap["Paris"] = c3;
  Ticket *itr = new Ticket(10, "Amsterdam", "Paris", 300);
  Ticket *itr1 = new Ticket(13, "Paris", "London", 300);
  Ticket *itr2 = new Ticket(15, "London", "Paris", 410);
  Ticket *itr3 = new Ticket(17, "London", "Amsterdam", 400);
  Ticket *itr4 = new Ticket(21, "Paris", "Amsterdam", 500);

  
  
  graph["Amsterdam"].insert(make_pair("Paris",itr));
  graph["Paris"].insert(make_pair("Amsterdam",itr4));
  graph["London"].insert(make_pair("Paris",itr2));
  graph["London"].insert(make_pair("Amsterdam",itr3));
  graph["Paris"].insert(make_pair("London",itr1));
  vector<string>  vec;
  best = new Itinerary(vec, INT_MAX);
  set<Ticket*>  used;
  vector<string> order;
  int budget = 5000;
    getLongestIternary("Amsterdam", 0, -1, 4000, used, order );
   
   vector<string> hello = best->order;
   for (auto h : hello) 
    cout << h <<  " ";
cout << "\n------------------------------\n";

 unordered_map<string, vector<string>> graph1;// = unordered_map<string, vector<string>>();
   graph1["Amsterdam"].push_back("Paris");
   graph1["Paris"].push_back("Amsterdam");
   graph1["London"].push_back("Paris");
   graph1["London"].push_back("Amsterdam");
   graph1["Paris"].push_back("London");
  
}