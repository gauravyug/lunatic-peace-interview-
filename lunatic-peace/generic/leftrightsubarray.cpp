class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, i = 0;
        int left_sum = 0;
        for (auto x : nums)
            sum += x;
        cout << sum << endl;
        for( const int& num : nums ) {
            if( left_sum * 2 == sum - num )  {
                cout << nums[i];
                return i;
            }
            left_sum += num;
            ++i;
        }
        return -1;
        
    }
};