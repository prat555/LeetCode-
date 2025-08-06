class Solution {
public:
    bool canJump(vector<int>& nums) {
        int tra=0;
        for (int i=0; i<nums.size(); i++){
            if (i>tra) return false;
            tra=max(tra,i+nums[i]);
        } return true;
    }
};