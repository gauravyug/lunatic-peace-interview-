#include <bits/stdc++.h>

using namespace std;
class Solution {
    public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        vector<vector<int>>::iterator itr;
        //for(auto edge : prerequisites) {
        for (itr = prerequisites.begin(); itr!= prerequisites.end(); ++itr)
            graph[itr.second].push_back(itr.first);
            ++indegree[itr->f];
        }
        queue<int> Q;
        for(int i = 0;i < numCourses;i++)
            if(indegree[i] == 0)
                Q.push(i);
        int counter = 0;
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            ++counter;
            for(auto v : graph[u])
            {
                if(--indegree[v] == 0)
                    Q.push(v);
            }
        }
        return counter == numCourses;   
    }
};

int main() {
    Solution sol;
    vector<pair<int, int>> prereq;// = {1,0};
    int course = 2;
    cout << sol.canFinish(course, prereq);
    return 0;
}