#include <iostream>
#include <map>
#include <vector>

using namespace std;
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    map <int, int> keymap;
    vector <int> vec;
    vector <int> count;
    RandomizedCollection() {
        keymap = map <int, int> ();
        vec = vector <int>();
        count = vector <int>();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int idx = 0;
        if (keymap.find(val) == keymap.end()) {
            vec.emplace_back(val);
            keymap[val] = vec.size() - 1;
            idx = keymap[val];
            count.push_back(1);
        }
        else {
            idx = keymap[val];
            count[idx] += 1;
        }
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (keymap.find(val) == keymap.end())
            return false;
        int idx = keymap[val];
        int cnt = count[idx];
        if (count[idx] == 1) {
            vec[idx] = vec[vec.size() -1];
            count[idx] = count[count.size() - 1];
            keymap[vec[idx]] = idx;
            vec.pop_back();
            count.pop_back();
            keymap.erase(val);
        }
        else {
            count[idx] -= 1;
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main()
{
    RandomizedCollection cache;// = new RandomizedCollection();
   cout <<  "Insert -1 : "<<cache.insert(-1) << endl;
    cout << "Insert -2 : "<< cache.insert(-2) << endl;
    cout << "Insert -1: " << cache.insert(-1) << endl;
    cout << "Insert 1: "<< cache.insert(1) << endl;
    cout << "gerandom" << cache.getRandom()<< endl;
    cout << "Remove -1" << cache.remove(-1) << endl;
    cout << "Remove: -2 " << cache.remove(-2) << endl; 
    return 0;

}