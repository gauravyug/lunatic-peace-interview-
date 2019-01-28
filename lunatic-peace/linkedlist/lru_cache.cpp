#include <iostream>
#include <map>
#include <deque>

using namespace std;

class lru {
	map <int, int > map_lru;
	deque<int> deq;
	int size;

	public:

	lru(int size): size(size){	}


	bool is_full(){
		return (deq.size() == size) ;
	}

	bool is_present(int value){
		if ( map_lru.find(value) == map_lru.end() ) {
			return false;
		} else {
			return true;
		}
	}

	void put(int key, int value){
		insert_deq(value);
		insert_map(key, value);
	}
    int get(int value)
    {
        int item = -1;
        map < int, int > :: iterator it ;
         if ( is_present(value) ){
			it = map_lru.find(value);
			item = it->second;
            return item;
		}
        return item;
    }
	void insert_deq(int value){
		int flag = 0;
		map < int, int > :: iterator it ;
		if ( is_present(value) ){
			flag = 1;
			it = map_lru.find(value);
			map_lru.erase(it, map_lru.end() );
			deque <int> :: iterator it;
			for (it= deq.begin(); it != deq.end(); it++)
			{
				if (*it == value)
					break;
			}
			deq.erase(it);
		}

		if ( is_full() ){
			deq.pop_back();
		}
		deq.push_front(value);
	}

	void insert_map(int key, int value){
		map_lru[key] = value;
	}

	void print(){
		deque <int> :: iterator it = deq.begin();

		for ( ; it!=deq.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
};

int main()

{
	lru LRU(4);
    LRU.put(1,1);
    LRU.put(2,2);
	LRU.print();
    cout << LRU.get(2) << endl;
    LRU.put(3,3);
	LRU.print();
    cout << LRU.get(3) << endl;;
    LRU.put(4,4);
    
    cout << LRU.get(4) << endl;
	LRU.print();

	/*LRU.insert_lru(1);
	LRU.print();
	LRU.insert_lru(2);
	LRU.print();
	LRU.insert_lru(3);
	LRU.print();
	LRU.insert_lru(4);
	LRU.print();
	LRU.insert_lru(5);
	LRU.print();
	LRU.insert_lru(6);
	LRU.print();
	LRU.insert_lru(7);
	LRU.print();
	LRU.insert_lru(8);
	LRU.print();
	LRU.insert_lru(6);
	LRU.print();*/
	
return 0;
}