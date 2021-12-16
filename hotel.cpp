
/*
{

	176 : 	[
				{
					"price" : 120,
					"features" : ["breakfast", "refundable"],
					"availbility" : 5
				}
			],
	177 : 	[
				{
					"price" : 130,
					"features" : ["breakfast"],
					"availbility" : 1
				},
				{
					"price" : 140,
					"features" : ["breakfast", "refundable", "wifi"],
					"availbility" : 3
				}
			],
	178 : 	[
				{
					"price" : 130,
					"features" : ["breakfast"],
					"availbility" : 2
				},
				{
					"price" : 140,
					"features" : ["breakfast", "refundable", "wifi"],
					"availbility" : 10
				}
			]	
}
Given above data map set, design an algorithm to get below output for below given input

I/P =>

{
	"checkin" : 176,
	"checkout" : 178,
	"features" : ["breakfast"]
	"rooms"    : 1
	
}
o/P =>

[
	{
		"price" : 250,
		"features" : ["breakfast"],
		"availbility" : 1
	},
	{
		"price" : 260,
		"features" : ["breakfast", "refundable"],
		"availbility" : 3
	}
]
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Room{
	public:
	 int price;
	vector<string> features;
	 int availbility;
	
	 Room(int price, vector<string> features,int availbility) {
		this->price = price;
		this->features = features;
		this->availbility = availbility;
	}
};

class Filter{
  public:
	 int checkin;
	 int checkout;
  vector<string> features;
   int rooms;
};

void backtrack(map<int, vector<Room*>> dataSource, vector<Room*> &result, Room* current, int checkin, int checkout, Room* data) {
	if(checkin == checkout) {
		Room *add = new Room(current->price, current->features, current->availbility);
		if (data != NULL)
			result.push_back(data);
			else result.push_back(add);
	
		return;
	}
	
	vector<Room*> nextDay =  dataSource[checkin];
	cout << checkin << " " <<  nextDay.size() << endl;
	for(Room *room : nextDay) {			
		if (room)  {
			cout << "backtrack room->price "<< room->price << endl;
			Room *add= NULL;
			current->price +=room->price;	
			cout << "current->price"	 << current->price << endl;
			if (current->availbility > room->availbility) {
				cout << current->availbility << " > " <<  room->availbility << endl;
				add = new Room(current->price, room->features, room->availbility);
				backtrack(dataSource, result, current, checkin + 1, checkout, add);
			}
			else
				backtrack(dataSource, result, current, checkin + 1, checkout, add);
			current->price -=room->price;
			//result.push_back(room);
		}
		
	}
	
	
}
vector<Room*> getRooms(map<int, vector<Room*>> dataSource, Filter *filter){
	
	vector<Room*> result;// = new vector<>();		
	vector<Room*> firstDay =  dataSource[filter->checkin];
	cout << "get rooms" << endl;
	for(Room *room : firstDay) {
		cout << "room->price " << room->price << endl;
    //result.push_back(room);
		backtrack(dataSource, result, room, filter->checkin +1  , filter->checkout, NULL);
	}
	cout << "hahahah";
	return result;
}




map<int, vector<Room*>> getDataSource(){
	
	map<int, vector<Room*>> dataSource;// = new HashMap<>();
	
	vector<string> features;// = new ArrayList<>();
	features.push_back("breakfast");
	features.push_back("refundable");
	
	vector<Room*> roomList;// = new ArrayList<>();
	roomList.push_back(new Room(120, features, 5));
	dataSource[176]= roomList;
	
	
	
	roomList.clear();// = new vector<Room*>();
	features.clear();
	features.push_back("breakfast");
	
	roomList.push_back(new Room(130, features, 1));
	features.clear();
	features.push_back("breakfast");
	features.push_back("refundable");
	features.push_back("wifi");
	roomList.push_back(new Room(140, features, 3));
  dataSource[177]= roomList;

	
	roomList.clear();// = new vector<Room*>();
	features.clear();
	features.push_back("breakfast");
	roomList.push_back(new Room(130, features, 1));
	roomList.push_back(new Room(140, features, 3));
  dataSource[178]= roomList;

	
	return dataSource;
	
}





int main() {
	
	map<int, vector<Room*>> datasource = getDataSource();
	
	Filter *filter = new Filter();
	vector<string> features ;//= new vector<string>();
	features.push_back("breakfast");
	filter->checkin=176;
	filter->checkout=178;
	filter->features = features;
	filter->rooms = 1;

	vector<Room*> result = getRooms(datasource, filter);
	cout << "\n\n\n\n\n";
//	cout << result.size();
	for (auto item : result) {
    cout << item->price << " ";
    for (auto itr : item->features) {
      cout << itr << " ";
    }
		cout << item->availbility;
    cout << endl;
  }
  return 0;
}