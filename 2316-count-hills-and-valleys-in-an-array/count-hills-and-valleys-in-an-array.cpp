class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0;
        for (int i=1,prev=0; i<nums.size()-1; ++i){
            if (nums[i]==nums[i+1]){
                continue;
            } if (nums[i]>nums[i+1] && nums[i]>nums[prev]){
                ++count;
            } if (nums[i]<nums[i+1] && nums[i]<nums[prev]){
                ++count;
            } prev=i;
        }
        return count;
    }
};