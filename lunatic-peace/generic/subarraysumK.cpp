class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curr_sum=0; // cumulated sum
        map<int,int> hash; // prefix sum recorder
        int ans = 0; // number of found subarray
        hash[0]++; // to take into account those subarrays that begin with index 0
        for(int i = 0; i < nums.size(); i++){
            curr_sum += nums[i];
            cout << curr_sum << endl;
            cout << curr_sum - k << endl;
            if(hash.count(curr_sum-k) != 0) {
                ans += hash[curr_sum-k];
                cout << "ANS" << ans << endl;
            }
            hash[curr_sum] += 1;
            /*cum += nums[i];
            cnt += rec[cum-k];
            rec[cum]++;*/
        }
        cout << "print map" << endl;
        map<int, int>::iterator it;
        for (it = hash.begin(); it != hash.end(); ++it) {
            cout << it->first << " " << it->second <<  endl;
        }
        
        return ans;
    }
};