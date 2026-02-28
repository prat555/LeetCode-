class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int a=0, b=1;
        for (int num: nums){
            if (num>0){
                ans[a]=num;
                a+=2;
            } else{
                ans[b]=num;
                b+=2;
            }
        } return ans;
    }
};