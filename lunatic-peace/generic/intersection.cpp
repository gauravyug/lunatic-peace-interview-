#include <bits/stdc++.h>

using namespace std;
// find intersection using set
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1,set2;
    vector<int> res;
    for(auto num:nums1){
            set1.insert(num);
    }
    for(auto num:nums2){
        if(set1.count(num)==1)
            set2.insert(num);
    }
    for(auto v:set2){
            res.push_back(v);            
    }
    return res; 
}

// Find intersecion using sorting.
vector<int> find_intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    sort(nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    for(int i=0, j=0; i<nums1.size() && j<nums2.size(); ) {
        if(nums1[i] == nums2[j]) {
            if(i == 0 || nums1[i] != nums1[i-1]) { 
                ret.push_back(nums1[i]);
            }
            ++i;
            ++j;
        }
        else if(nums1[i] < nums2[j]) {
            ++i;
        }
        else {
            ++j;
        }
    }
    return ret;
}


int main()
{
    vector<int> vec1 = {1,2,2,1};
    vector<int> vec2 = {2,2};

    vector<int> ret;
    cout << "Intersection using set" << endl;
    ret = intersection(vec1, vec2);
    for (auto i : ret)
        cout << i << endl;
    
    cout << "Intersection using sorting" << endl;
    ret = find_intersection(vec1, vec2);
    for (auto i : ret)
        cout << i << endl;
    return 0;
}