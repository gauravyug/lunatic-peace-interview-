#include <vector>
#include <unordered_map>
using namespace  std;
/*
    Linked List Node
*/
class DNode
{
    public:
        int key;
        int chksum;
        int data;
        DNode* next;
        DNode* prev;
        DNode(int key, int value, int csum) : key(key), data(value), next(NULL), prev(NULL), chksum(csum){ }
};

class DoublyLinkedList
{
    private:
        DNode* head;
        DNode* tail;
    public:
        DoublyLinkedList() : head(NULL), tail(NULL){ }
        ~DoublyLinkedList() { };

        bool is_empty() {
            return (tail == NULL );
        }

        DNode* insert_node(int key, int value, int k) {
            DNode *temp = new DNode(key, value, k);
            if(!head && !tail) {
                head = tail = temp;
            }
            else {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            return temp;
        }

        void delete_node(DNode *node_ptr) {
            if (head->next == NULL)
            {
                head->prev = NULL;
                delete node_ptr;
                return;
            }
            if (node_ptr == head) {
                head = head->next;
                head->next->prev = NULL;
                delete node_ptr;
                return;
            }
            if (node_ptr == tail) {
                tail = tail->prev;
                tail->next = NULL;
                delete node_ptr;
                return;
            }
            node_ptr->prev->next = node_ptr->next;
            node_ptr->next->prev = node_ptr->prev;
            delete node_ptr;
            return;
        }

        DNode* get_tail_page() {
            return tail;
        }
};

class Fastmap {
    private:
        int size;
        int key;
        DoublyLinkedList *list;
        unordered_map<int, DNode*> hash;
        vector <int> my_vec();
        unordered_map<int,int> key_map;
    public:
        Fastmap();
        ~Fastmap();
    
        bool insert(int x);
        bool search(int x);
        bool remove(int x);
        int get_random();
};