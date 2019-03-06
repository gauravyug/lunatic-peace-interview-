/*  
    @Gaurav YadavCS-11 Asn 2, least_recently_used_cache.h
    Purpose: Implements LRU

    @author Gaurav Yadav
    @email gauravyug@gmail.com
    @version 1.1 
    @date 15-Oct-18 
*/
#ifndef LRU_CACHE_H_
#define LRU_CACHE_H_

#include <unordered_map>
using namespace  std;
/*
    Linked List Node
*/
class DNode
{
    public:
        int key;
        int data;
        DNode* next;
        DNode* prev;
        DNode(int key, int value) : key(key), data(value), next(NULL), prev(NULL){ }
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

        DNode* add_page_to_head(int key, int value) {
            DNode *page = new DNode(key, value);
            if(!head && !tail) {
                head = tail = page;
            }
            else {
                page->next = head;
                head->prev = page;
                head = page;
            }
            return page;
        }

        void erase_page_from_tail() {
            if (is_empty())
                return;
            if (head == tail) {
                delete tail;
                head = tail = NULL;
            } 
            else {
                DNode* del = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete del;
            }
        }

        DNode* get_tail_page() {
            return tail;
        }

        void splice_page_to_head(DNode* page) {
            if (head == page)
                return;

            if (tail == page) {
                tail = tail->prev;
                tail->next = NULL;
            }
            else {
                page->prev->next = page->next;
                page->next->prev = page->prev;
            }
            page->next = head;
            page->prev = NULL;
            head->prev = page;
            head = page;
        }
};

class LRUCache {
    public:
        LRUCache(int aCacheSize);
        ~LRUCache();
        void put(int key, int pageNumber);
        int get(int value);
private:
        int cache_capacity;
        int current_size;
        DoublyLinkedList *pageList;
        std::unordered_map<int ,DNode*> pageHash;
};
#endif