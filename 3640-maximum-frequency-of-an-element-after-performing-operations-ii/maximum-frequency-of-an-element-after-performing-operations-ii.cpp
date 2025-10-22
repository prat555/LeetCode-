class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int ans = 0;
        map<int, int> count;
        
        // Count frequency of each element
        for (int num : nums) {
            count[num]++;
        }
        
        // Sort the array for sliding window approach
        sort(nums.begin(), nums.end());
        
        // Try each unique value as a potential target
        for (const auto& [target, freq] : count) {
            // Elements already equal to target
            ans = max(ans, freq);
            
            // Find how many elements can be modified to become target
            int l = lower_bound(nums.begin(), nums.end(), target - k) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), target + k) - nums.begin() - 1;
            
            // Total elements in range [target-k, target+k]
            int inRange = r - l + 1;
            
            // We can modify at most numOperations elements
            // Result is original frequency + min(operations, elements that can be changed)
            ans = max(ans, min(freq + numOperations, inRange));
        }
        
        // Try values not in the array using sliding window
        int j = 0;
        for (int i = 0; i < n; i++) {
            // Expand window while elements are within 2*k range
            while (j < n && nums[j] - nums[i] <= 2 * k) {
                j++;
            }
            // Window size is j - i, we can pick at most numOperations elements
            ans = max(ans, min(j - i, numOperations));
        }
        
        return ans;
    }
};