class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int ans = 0;
        map<int, int> count;
        
        for (int num : nums) {
            count[num]++;
        } 
        sort(nums.begin(), nums.end());
        
        for (const auto& [target, freq] : count) {
            ans = max(ans, freq);
            int l = lower_bound(nums.begin(), nums.end(), target - k) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), target + k) - nums.begin() - 1;         
            int inRange = r - l + 1;
            ans = max(ans, min(freq + numOperations, inRange));
        }
        
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= 2 * k) {
                j++;
            }
            ans = max(ans, min(j - i, numOperations));
        }
        
        return ans;
    }
};