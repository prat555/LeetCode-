class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long s=0, k=0;
        int m=0;
        for (int x: nums) s+=x;
        for (int i=0; i<nums.size()-1; i++){
            s-=nums[i];
            k+=nums[i];
            if ((s-k)%2==0) m++;
        } return m;
    }
};