/*
1023. Camelcase Matching
A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it 
equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is 
true if and only if queries[i] matches the pattern

Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output:         [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
*/
#include <bits/stdc++.h>

using namespace std;
vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res(queries.size(), false);
        for (int idx = 0; idx< queries.size(); idx++) {
            int j = 0;
            int i = 0;
            string str = queries[idx];
            string str1;
            for (; i < str.size();i++) {
                char q = str[i]; 
                if (isupper(q) || (j < pattern.size() && pattern[j] == q)){
                    str1.push_back(q);
                    ++j;
                } 
            }
            res[idx] = (str1 == pattern) ? true : false;    
        }
        return res;
    }
int main(){
    vector<string> queries;
    queries.push_back("FooBar");
    queries.push_back("FooBarTest");
    queries.push_back("FootBall");
    queries.push_back("FrameBuffer");
    queries.push_back("ForceFeedBack");
    vector <bool> ans;
    ans = camelMatch(queries, "FB");
    for (int i = 0; i < ans.size(); i++) 
    {
        cout << ans[i] << endl;
    }
    return 0;
}