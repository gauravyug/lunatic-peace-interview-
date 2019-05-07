#include <bits/stdc++.h>
using namespace std;

class SortedIterator {
    private:

    public:
        SortedIterator(vector<list<int>> list);
        int next();
        bool hasnext();
};

int main() {
    vector<list<int>> lists;
    list<int> a = {1,2,3};
    list<int> b = {1,2,3};
    list<int> c = {1,2,3};
    lists.push_back(a);
    lists.push_back(b);
    lists.push_back(c);
    SortedIterator itr(lists);
    return 0;
}