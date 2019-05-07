#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mp;
        for(auto i:nums1){
            mp.insert(i);
        }
        vector<int>ans;
        for(auto i:nums2){
            if(mp.find(i)!=mp.end()){
                mp.erase(i);
                ans.push_back(i);
            }
        }
        return ans;
}

int main()
{
    vector <int> num1 = {1, 3, 4, 5, 7};
    vector <int> num2 = {2, 3, 5, 6};
    vector <int>  ans = intersection (num1, num2);
    for (auto i: ans)
        cout << i << " ";
    return 0;
}