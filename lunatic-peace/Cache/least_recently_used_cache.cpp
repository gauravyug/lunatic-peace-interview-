#include <iostream>
#include "least_recently_used_cache.h"

LRUCache::LRUCache(int aCacheSize)
{
    this->cache_capacity = aCacheSize;
    pageList = new DoublyLinkedList();
    pageHash = unordered_map<int, DNode*>();
}

LRUCache::~LRUCache() {
      std::unordered_map<int, DNode*>::iterator itr;
      for(itr = pageHash.begin(); itr != pageHash.end(); itr++) {
          delete itr->second;
      }
      delete pageList;
}

/*
    Algorithh:
    1. Find the key in pageHash, if not found return -1
    2. get the data @ given key from pageHash
    3. move page at  key to head of list.
*/
int LRUCache::get(int key)
{
    if(pageHash.find(key)==pageHash.end()) {
       return -1;
    }
    int val = pageHash[key]->data;
    pageList->splice_page_to_head(pageHash[key]); //  As its a hit hence this page should move towards head
    return val;
}
/*
    Algorithm:
    1. first find the page in pageHash
        a. if not found than, add value @ key and move newly added page to head of the DLL
        b. return from here
    2. cache evict logic. i.e if cache is full
        > if cache_capacity is full than, get the key from list's tail  and erase same key from hash and from DLL
    3. add new page to head of list
*/

void LRUCache::put(int key, int value)
{
    if(pageHash.find(key) != pageHash.end()) {
        pageHash[key]->data = value;
        pageList->splice_page_to_head(pageHash[key]);
        return;
    }
    if (this->current_size == this->cache_capacity) { //Cache eviction rule appies
        int k = pageList->get_tail_page()->key;
        //Erase key (k) from hash map followed by erasing page from tail
        pageHash.erase(k); 
        pageList->erase_page_from_tail();
        this->current_size--;  
    }
    // Add new page to head of DLL
    DNode *page = pageList->add_page_to_head(key, value);
    this->current_size++;
    pageHash[key] = page;
}

int main()
{

    LRUCache cache(2);// = new LRUCache(2);

  cache.put(2,2);
  cout << cache.get(2) << endl;
  cout << cache.get(1) << endl;
  cache.put(1,1);
  cache.put(1,5);
  cout << cache.get(1) << endl;
  cout << cache.get(2) << endl;
  cache.put(8,8);
  cout << cache.get(1) << endl;
  cout << cache.get(8) << endl;
    return 0;
}



































int writers; // Number writer threads that want to enter the critical section (some or all of these may be blocked)
int writing; // Number of threads that are actually writing inside the C.S. (can only be zero or one)
int reading; // Number of threads that are actually reading inside the C.S.
// if writing !=0 then reading must be zero (and vice versa)
reader() {
    pthread_mutex_lock(&m)
    while (writers)
        pthread_cond_wait(&turn, &m)
    // No need to wait while(writing here) because we can only exit the above loop
    // when writing is zero
    reading++
    pthread_mutex_unlock(&m)

  // perform reading here
    pthread_mutex_lock(&m)
    reading--
    pthread_cond_broadcast(&turn)
    pthread_mutex_unlock(&m)
}

writer() {
    pthread_mutex_lock(&m)  
    writers++  
    while (reading || writing)   
        pthread_cond_wait(&turn, &m)  
    writing++  
    pthread_mutex_unlock(&m)  
    // perform writing here  
    pthread_mutex_lock(&m)  
    writing--  
    writers--  
    pthread_cond_broadcast(&turn)  
    pthread_mutex_unlock(&m)  
}
#define MY_OFFSET(TYPE, ELEMENT) ((size_)&(((TYPE*)0)->ELEMENT))
#define MY_SIZEOF(TYPE) (char*)(&TYPE + 1) - (char*) (&TYPE) 