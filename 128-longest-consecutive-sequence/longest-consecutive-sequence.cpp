class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx=0;
        unordered_set<int> kk(nums.begin(),nums.end());
        for (int val:kk){
            if (!kk.count(val-1)){
                int cnt=0;
                while (kk.count(val)){
                    cnt++;
                    val+=1;
                } mx=max(cnt,mx);
            }
        } return mx;
    }
};