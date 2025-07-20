class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int li=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int ri=lower_bound(nums.begin(),nums.end(),target+1)-nums.begin();
        if (li==ri){
            return {-1,-1};
        } else {
            return {li,ri-1};
        }
    }
};