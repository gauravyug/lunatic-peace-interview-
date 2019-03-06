#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    struct Node {
        int key; // key of the element.
        int val; // value of the ement.
        int fre; // usage frequency
        int timeStamp; // the latest time stamp when this element is accessed.
        Node(): key(-1), val(-1), timeStamp(-1), fre(0) {}
        Node(int k, int v, int ts): key(k), val(v), timeStamp(ts), fre(1) {}
    };

    LFUCache(int capacity) {
        Cap = capacity;
        Node* dummy = new Node();
        pq.push_back(dummy); // The pq start from pq[1].
        ts = 0;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        int index = mp[key];
        int val = pq[index]->val;
	    pq[index]->fre++;
	    pq[index]->timeStamp = ++ts;
        sink(index);
        return val;
    }
    
    void put(int key, int value) {
        if(Cap <= 0) return;
	if(mp.count(key)) {
	   int index = mp[key];
	   pq[index]->val = value;
	   get(key);
	}
	else {
	    if(pq.size() - 1 == Cap) {
	        int oldKey = pq[1]->key;
		mp.erase(oldKey);
		Node* newnode = new Node(key, value, ++ts);
		pq[1] = newnode;
		mp[key] = 1;
		sink(1);
	    }
	    else {
	        Node* newnode = new Node(key, value, ++ts);
		pq.push_back(newnode);
		mp[key] = pq.size() - 1;
		swim(pq.size() - 1);
	    }
	}
    }
    
private:
	vector<Node*> pq; // A priority queue, with the least usage frequency and least recently used element at the top.
	unordered_map<int, int> mp; // A mapping from the key of the element to its index in the priority queue.
	int Cap; // Capcity of the cache
	int ts; // time-stamp: indicate the time stamp of the latest operation of an element. According to the requirement of LFU cache, when we need to evict an element from the cache, but there are multiple elements with the same minimum frequency, then the least recently used element should be evicted.

    /*
     * Recursively sink a node in priority queue. A node will be sinked, when its frequency is larger than any of its
     * children nodes, or the node has the same frequency with a child, but it is recently updated. 
     */
	void sink(int index) {
	    int left = 2 * index, right = 2 * index + 1, target = index;
	    if(left < pq.size() && pq[left]->fre <= pq[target]->fre) // If the left child has the same frequency, we probably need to swap the parent node and the child node, because the parent node is recently accessed, and the left child node was accessed at an older time stamp.
               target = left;
            if(right < pq.size()) { 
                if(pq[right]->fre < pq[target]->fre || (pq[right]->fre == pq[target]->fre && pq[right]->timeStamp < pq[target]->timeStamp)) // If right child has the same frequency and an older time stamp, we must swap it.
                     target = right;
		}
		if(target != index) {
		    myswap(target, index);
	            sink(target);
		}
	}
    
    /*a
     * Recursively swim a node in priority queue. A node will be swimmed, when its frequency is less than its
     * parent node. If the node has the same frequency with its parent, it is not needed to be swimmed, because
     * it is recently accessed.
     */
	void swim(int index) {
	    int par = index / 2;
	    while(par > 0 && pq[par]->fre > pq[index]->fre) {
	        myswap(par, index);
		index = par;
		par /= 2;
	    }
	}

	void myswap(int id1, int id2) {
	    swap(pq[id1], pq[id2]);
	    mp[pq[id1]->key] = id1;
	    mp[pq[id2]->key] = id2;
	}
};

int main()
{
    //LFUCache cache = new LFUCache( 2 /* capacity */ );
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;        // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2)<< endl;       // returns -1 (not found)
   cout <<  cache.get(3)<< endl;       // returns 3.
    cache.put(4, 4);    // evicts key 1.
    cout << cache.get(1)<< endl;       // returns -1 (not found)
    cout << cache.get(3)<< endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4
    return 0;
}