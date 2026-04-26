class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnd1, cnt1=0, cnd2, cnt2=0;
        for (int n:nums){
            if (n==cnd1) cnt1++;
            else if (n==cnd2) cnt2++;
            else if (cnt1==0){
                cnd1=n;
                cnt1++;
            } else if (cnt2==0){
                cnd2=n;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        } vector<int> ans;
        if (count(nums.begin(),nums.end(),cnd1)>nums.size()/3) ans.push_back(cnd1);
        if (count(nums.begin(),nums.end(),cnd2)>nums.size()/3) ans.push_back(cnd2);
        return ans;
    }
};