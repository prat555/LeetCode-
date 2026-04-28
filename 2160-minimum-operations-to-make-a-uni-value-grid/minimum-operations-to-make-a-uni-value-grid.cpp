class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int mod=grid[0][0]%x;
        for (auto &row:grid){
            for (auto &val:row){
                if (val%x!=mod) return -1;
                nums.push_back(val/x);
            }
        } nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        int med=nums[nums.size()/2];
        int cnt=0;
        for (int val:nums) cnt+=abs(val-med);
        return cnt;
    }
};