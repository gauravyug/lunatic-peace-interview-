class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         if (nums.size() < 3)
            return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (auto i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                    results.push_back({nums[i], nums[j], nums[k]});
                if (sum <= 0)
                    do { 
                        ++j; 
                    } while (j < k && nums[j] == nums[j - 1]);
                if (sum >= 0)
                    do { 
                        --k; 
                       } while (j < k && nums[k] == nums[k + 1]);
            }
        }
        return results;
        
    }
};