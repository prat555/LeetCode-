class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        for (int i = 0; ; ++i) {
            if (seen.count(nums[i])) {
                return nums[i];
            } seen.insert(nums[i]);
        }
    }
};