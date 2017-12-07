#include <iostream>
using namespace std;
 
const int ALPHABET_SIZE = 26;

struct TrieNode {
        struct TrieNode* child[ALPHABET_SIZE];
        bool             isEndOfWord; // represent end of word
        
       int count;
       int index;
       
};

int wordCountInTrie(struct TrieNode *root);
/*
 * will return new initialized Trie Node
 * */
struct TrieNode* createNode()
{
        struct TrieNode *pNode = new  TrieNode;
        int count;
        pNode->isEndOfWord = false;

        for (int i = 0; i < ALPHABET_SIZE; i++)
                pNode->child[i] =  NULL;
        pNode->count = 0;
        pNode->index = -1;
        return pNode;
}

void insert(struct TrieNode *root, string key)
{
        struct TrieNode *temp = root;

        for (int i=0; i< key.length(); i++) {
                int index = key[i] -'a';

                if (!temp->child[index])
                        temp->child[index] = createNode();

                temp = temp->child[index];
        }
        temp->count++;
        temp->isEndOfWord = true;
}

void insert(struct TrieNode *root, string key, int index)
{                        
        struct TrieNode *temp = root;
                         
        for (int i=0; i< key.length(); i++) {
                int index = key[i] -'a';
                         
                if (!temp->child[index])
                        temp->child[index] = createNode();
                         
                temp = temp->child[index];
        }                
        temp->index = index;   
        temp->isEndOfWord = true;                                                                                                                                                                                  
}

bool search(struct TrieNode *root,string key) 
{
        struct TrieNode *pNode = root;
        for (int i = 0; i< key.length(); i++) {
                int index = key[i] - 'a';
                if (!pNode->child[index] )
                        return false;

                pNode = pNode->child[index];
        }
        return (pNode != NULL && pNode->isEndOfWord);

}

int searchCount(struct TrieNode *root,string key) 
{
        struct TrieNode *pNode = root;
        for (int i = 0; i< key.length(); i++) {
                int index = key[i] - 'a';
                if (!pNode->child[index] )
                        return false;

                pNode = pNode->child[index];
        }
        return (pNode->count);// != NULL && pNode->isEndOfWord);

}


/*int delete(struct TrieNode *root, int item)
{
}*/

void countquery(string arr[],int n, string q[], int m)
{
        int count = 0;
        for (int i=0; i<m;i++) {
                count = 0;
                for (int j = 0; j<n;j++)
                {
                       if(!q[i].compare(arr[j]))
                            count++;

                }
                cout << q[i] <<": count is :" << count <<"\n";
        }
        struct TrieNode *root = createNode();
        for (int i =0; i < n;i++) {
                insert(root, arr[i]);
        }

   cout << "No of words in trie are : " << wordCountInTrie(root)<<"\n";
        for (int i =0; i < m;i++) {
                cout << q[i] << "count is :" << searchCount(root, q[i]) <<"\n";
        }
}

bool sortarray(struct TrieNode* root, string keys[], int n)
{
        if (root == NULL)
                return false;

        for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (root->child[i] != NULL) {
                        if (root->child[i]->index != -1)
                        {
                                cout << keys[root->child[i]->index] << " ";
                        }
                        sortarray(root->child[i], keys, n);
                }
        }
}

int wordCountInTrie(struct TrieNode *root)
{
        int result = 0;
        struct TrieNode *temp = root;
        if (root->isEndOfWord)
                result++;

        for (int i =0; i < ALPHABET_SIZE; i++)
        {
                if (temp->child[i])
                        result += wordCountInTrie(root->child[i]);
                                
        }
        return result;
}

int wordformation(struct TrieNode *root, string key)
{
        struct TrieNode *pNode = root;
        bool prefixFound = false;

        for (int i =0; i< key.length(); i++) {
                int index = key[i] - 'a';
                if (pNode->child[index])
                        if (pNode->child[index]->isEndOfWord)
                        {
                               prefixFound = true;
                        }
        }
}
string reverse(string str)
{
        int n = str.length();
        string temp = str;;
    // Swap character starting from two
    // corners
        for (int i=0; i<n/2; i++)
                swap(temp[i], temp[n-i-1]);
        return temp;
}
bool checkPalindromePair( struct TrieNode *pNode, string key)
{
        cout << "palindrome pair \n\n";
        for  (int i = 0; i < key.length(); i++)
        {
                int index = key[i] - 'a';
                if (pNode->child[index] != NULL) {
                        string str = reverse(key);
                        if (search(pNode, str)) {
                                cout << "word found\n";
                        }
                }
                else {
                        pNode->child[index] = createNode();
                        pNode = pNode->child[index]; 

                }
        }
}

int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);


    struct TrieNode *root = createNode();
    string dict[] = {"geeks", "geeks", "skeeg", "keeg", "abc", "bc"};
     int x = sizeof(dict)/sizeof(dict[0]);

        struct TrieNode *pNode = createNode();
    for (int i = 0; i < n; i++)
        checkPalindromePair(pNode, dict[i]);
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    cout << "No of words in trie are : " << wordCountInTrie(root)<<"\n";
    struct TrieNode *temp = createNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(temp, keys[i], i);
cout << "Sorted Array is \n ";
   sortarray(temp, keys, n);
    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           
            cout << "No\n";

   string  arr[] = {"wer", "wer", "tyu", "oio", "tyu"};
   string q[] =   {"wer", "tyu", "uio"};
   n = sizeof(arr)/sizeof(arr[0]);
   int m  = sizeof(q)/sizeof(q[0]);
   countquery(arr,n, q,m);

    return 0;
}


