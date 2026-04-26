class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cur=1<<30, n=nums.size();
        for (int i=0; i<n-2; i++){
            int l=i+1, r=n-1;
            while (l<r){
                int s=nums[i]+nums[l]+nums[r];
                if (s==target) return s;
                if (abs(cur-target)>abs(s-target)) cur=s;
                if (s>target) r--;
                else l++;
            }
        } return cur;
    }
};