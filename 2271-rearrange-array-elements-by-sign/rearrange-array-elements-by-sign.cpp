class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int a=0, b=1;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]>0){
                ans[a]=nums[i];
                a+=2;
            } else{
                ans[b]=nums[i];
                b+=2;
            }
        } return ans;
    }
};