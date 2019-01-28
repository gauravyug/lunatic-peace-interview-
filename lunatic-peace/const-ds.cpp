#include <iostream>
#include "const-ds.h"

Fastmap::Fastmap()
{
    size = 0;
    key = 0;
    list = new DoublyLinkedList();
    hash = unordered_map<int,  DNode*>();
    key_map = unordered_map<int, int> ();
}

Fastmap::~Fastmap(){}

bool Fastmap::insert(int x)
{
    DNode * node = list->insert_node(x, x,key);
    if (node != NULL) {
        hash[x] = node;
        my_vec.emplace_back(x);
        key_map[key] = x;
        this->size++;
        this->key++;
        return true;
    }
    return false;
}

bool Fastmap::remove(int x)
{
    if (size != 0) {
        if (hash.find(x) != hash.end()) {
        
            int val = hash[x]->chksum;
            list->delete_node(hash[x]);
            hash.erase(x);
            key_map.erase(val);
            this->size--;
            return true;
        }
    }
    return false;
}

bool Fastmap::search(int x)
{
    if (hash.find(x) != hash.end()) {
        return true;
    }
    else 
        return false;

}

int Fastmap::get_random()
{
    if (size == 1) {
        unordered_map<int, DNode*>::iterator it1 ;
        for (it1 = hash.begin(); it1!=hash.end(); ++it1) 
            return it1->first;
    }
    else{
        int index =rand() % this->size;
        return hash_map[index];
        //return ptr->data;
    }
    //if (this->size != 0)
        //return hash[rand() % this->size];
}

int main()
{
    Fastmap fmap;
   // cout << "Remove 1 " << fmap.remove(0) << endl;
    //cout << "Remove 2 " << fmap.remove(0) << endl;
    fmap.insert(-1);
    cout << "Remove 1 " << fmap.remove(-2) << endl;
    fmap.insert(-2);
    cout << "random  " << fmap.get_random() << endl;
    cout << "Remove 3 " << fmap.remove(-1) << endl;
    fmap.insert(-2);
    cout << "random  " << fmap.get_random() << endl;
    fmap.insert(3);
    fmap.insert(8);

    /*cout << "random  " << fmap.get_random() << endl;
    cout << "Remove 1 " << fmap.remove(1) << endl;
    cout << "Remove 2 " << fmap.remove(2) << endl;
    cout << "Remove 3 " << fmap.remove(3) << endl;
    cout << "Search 2 " << fmap.search(2) << endl;;
    cout << "Search 4 " << fmap.search(4) << endl;
    cout << "random  " << fmap.get_random() << endl;
    cout << "Search 4 " << fmap.search(4) << endl;
    cout << "random  " << fmap.get_random() << endl;*/

}