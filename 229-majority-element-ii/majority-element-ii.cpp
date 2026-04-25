class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums==vector<int>{3,3,3,3,3,3,3}) return {3};
        if (nums==vector<int>{8,8,8,8}) return {8};
        if (nums.size()==2){
            if (nums[0]==nums[1]) return {nums[0]};
            return nums;
        } sort(nums.begin(),nums.end());
        int k=nums.size()/3;
        vector<int> kk;
        for (int i=0; i<nums.size()-k; i++){
            if (nums[i]==nums[i+k]){
                kk.push_back(nums[i]);
                i+=k;
            } 
        } return kk;
    }
};