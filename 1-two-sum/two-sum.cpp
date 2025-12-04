class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i=0; i<nums.size(); i++){
            int cmp=target-nums[i];
            if (mp.count(cmp)) return {mp[cmp],i};
            mp[nums[i]]=i;
        } return {};
    }
};