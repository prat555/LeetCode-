class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> q;
        int sum=0, cnt=0;
        q[0]=1;
        for (int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if (q.count(sum-k)) cnt+=q[sum-k];
            q[sum]++;
        } return cnt;
    }
};