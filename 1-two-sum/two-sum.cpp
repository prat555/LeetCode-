class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, k=1;
        while (i!=nums.size()){
            if (nums[i]+nums[k]==target){
                return {i,k};
                break;
            } else if (nums[i]+nums[k]!=target && k!=nums.size()-1) k++;
            else{
                i++;
                k=i+1;
            }

        } return {};
    }
};