// C++ program to find minimum breaks needed
// to break a string in dictionary words.
#include <bits/stdc++.h>
using namespace std;
 
const int ALPHABET_SIZE = 26;
 
// trie node
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node 
    // represents end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;
 
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
 
// function break the string into minimum cut
// such the every substring after breaking 
// in the dictionary.
void minWordBreak(struct TrieNode* root, 
          string key, int start, int* min_Break, 
                                 int level = 0)
{
    struct TrieNode* pCrawl = root;
 
    // base case, update minimum Break
    if (start == key.length()) {        
        *min_Break = min(*min_Break, level - 1);
        return;
    }
 
    // traverse given key(pattern)
    int minBreak = 0;   
    for (int i = start; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return;
 
        // if we find a condition were we can 
        // move to the next word in a trie
        // dictionary
        if (pCrawl->children[index]->isEndOfWord)
            minWordBreak(root, key, i + 1,
                           min_Break, level + 1);
 
        pCrawl = pCrawl->children[index];
    }
}
 
// Driver program to test above functions
int main()
{
    string dictionary[] = { "Cat", "Mat",
   "Ca", "Ma", "at", "C", "Dog", "og", "Do" };
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    struct TrieNode* root = getNode();
 
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);
    int min_Break = INT_MAX;
 
    minWordBreak(root, "CatMatat", 0, &min_Break, 0);
    cout << min_Break << endl;
    return 0;
}
