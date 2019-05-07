/*
We sort our clips by the starting point. Since clips are sorted, we need to only analyze each clip once. 
For each round, we check all overlapping clips (clips[i][0] <= st) and advance our stitching position as 
far as we can (end = max(end, clips[i][1])).

Return -1 if we cannot advance our stitching position (st == end).
*/

#include <bits/stdc++.h>
using namespace std;

int videoStitching(vector<vector<int>>& clips, int T) 
    {
        int ans = 0;
        map<int,int> clip_ends;
        for(vector<int> &clip:clips)                                     
            clip_ends[clip[0]] = max(clip_ends[clip[0]],clip[1]); // sort the clips by starting point

        map<int,int>::iterator itr = clip_ends.begin();
        for (auto clip : clip_ends)
            cout << clip.first << " : " << clip.second ;
        
        //For each round, we check all overlapping clips (clips[i][0] <= st) and advance our stitching
        //position as far as we can (end = max(end, clips[i][1])).
        for (int curr_pos = 0, curr_end = 0; curr_pos < T; curr_pos = curr_end, ++ans) {
            for(; itr != clip_ends.end() && itr->first <= curr_pos; ++itr) {
                curr_end = max(curr_end, itr->second);
            }
            if (curr_pos == curr_end) 
                return -1;
            //++ans;
        }
        cout << endl;
        return ans;
    }

int myvideoStitching(vector<vector<int>>& clips, int T, int res = 0) {
    map<int, int> m;
    for (auto clip : clips) 
        m[clip[0]] = max(m[clip[0]], clip[1]);
    auto it = m.begin();
    for (auto m1 : m)
            cout << m1.first << " : " << m1.second << endl ;
            // (0:2), (1:9), (4:6), (5:9), (8:10)
    for (auto pos = 0, end = 0; pos < T; pos = end, ++res) {
        for (; it != m.end() && it->first <= pos; ++it) {
            end = max(end, it->second);
        }
        if (pos == end) return -1;
    }
    cout << endl;
    return res;
}

    int main()
    {
        vector<vector<int>> clips = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};     
        cout << myvideoStitching(clips, 10) << endl;
        //cout << videoStitching(clips, 10) << endl;

    }