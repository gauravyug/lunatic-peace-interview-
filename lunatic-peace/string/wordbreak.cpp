#include <iostream>
using namespace std;
 
/* A utility function to check whether a word is 
  present in dictionary or not. An array of strings 
  is used for dictionary.  Using array of strings for
  dictionary is definitely not a good idea. We have 
  used for simplicity of the program*/

#define NO_OF_CHARS 26

struct TrieNode{
        struct TrieNode *children[NO_OF_CHARS];
        bool isEndofWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *createNode()
{
        struct TrieNode *tNode = new TrieNode();
        for (int i = 0 ;i<NO_OF_CHARS; i++) 
        {
                tNode->children[i] = NULL;
        }
        return tNode;
}
void insertInTrie(struct TrieNode *root, string key)
{
        struct TrieNode *ptr = root;
        for (int i = 0; i< key.length(); i++) {
                int index = key[i] - 'a';
                if (!ptr->children[index])
                        ptr->children[index] = createNode();
                ptr = ptr->children[index] ;
        }
        ptr->isEndofWord = true;
}


bool searchInTrie(struct TrieNode *root, string key)
{
        struct TrieNode *ptr = root;
        for (int i = 0; i< key.length(); i++) {
                int index = key[i] - 'a';
                if (!ptr->children[index])
                        return true;
                ptr = ptr->children[index] ;
        }
        return (ptr !=NULL &&& ptr->isEndofWord) ;
}

int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}

bool wordBreakUsingTrie(struct TrieNode *root, string str)
{
        struct TrieNode *pNode = root;
        if (str.length() == 0)
                return true;

        for (int i = 0; i< str.length(); i++) {
                if (searchInTrie(pNode, str.substr(0,i)) 
                                 && wordBreakUsingTrie(pNode, str.substr(i, str.length() - i)))
                        return true;
        }
        return false;
}
bool wordBreakUsingDP(string word)
{
        int len = word.length();
        if (len == 0)
                return true;

        bool lookup[len+1] = {false};

        for (int i = 1; i <= len ;i++) {
                if (lookup[i] == false && dictionaryContains(word.substr(0,i)))
                        lookup[i] = true;
                
                if (lookup[i] == true) {
                        if (i == len)
                                return true;

                        for (int j = i+1; j <= len;j++) {
                                 if (lookup[j] == false && dictionaryContains(word.substr(i,j-i)))
                                        lookup[j] = true;

                                 if (j == len && lookup[j] ==  true)
                                         return true;
                        }

                }
        }
        return false;
}


int main()
{
    wordBreakUsingDP("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreakUsingDP("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreakUsingDP("")? cout <<"Yes\n": cout << "No\n";
    wordBreakUsingDP("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreakUsingDP("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreakUsingDP("samsungandmangok")? cout <<"Yes\n": cout << "No\n";

    string dictionary[] = {"mobile","samsung","sam",
                           "sung","ma\n","mango",
                           "icecream","and","go","i",
                           "like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    struct TrieNode *root = createNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insertInTrie(root, dictionary[i]);

    wordBreakUsingTrie(root, "ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreakUsingTrie(root, "iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreakUsingTrie(root, "")? cout <<"Yes\n": cout << "No\n";
    wordBreakUsingTrie(root, "ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreakUsingTrie(root, "samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreakUsingTrie(root, "samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}
