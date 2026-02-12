class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool s[1001]={false};
        vector<int> nums;
        for (int x: nums1) s[x]=true;
        for (int x: nums2){
            if (s[x]){
                nums.push_back(x);
                s[x]=false;
            }
        } return nums;
    } 
};