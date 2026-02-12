class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        bool s[10000]={false};
        for (int x: nums) s[x]=true;
        for (int i=0; i<=n; i++){
            if (s[i]==false) return i;
        } return -1;
    }
};