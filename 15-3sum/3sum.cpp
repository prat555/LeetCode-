class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int asize = nums.size();
        vector<vector<int>> arr;
        if (asize < 3) return arr;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < asize - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > 0) {
                break;
            }
            
            int left = i + 1;
            int right = asize - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    arr.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return arr;
    }
};