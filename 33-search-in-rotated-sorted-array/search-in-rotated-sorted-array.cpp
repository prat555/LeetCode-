class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k, low, high;
        int n=nums.size();
        for (int i=0; i<n-1; i++){
            if (nums[i]>nums[i+1]) k=i+1;
        } if (target>=nums[k] && target<=nums[n-1]){
            low=k;
            high=n-1;
        } else{
            low=0;
            high=k-1;
        }
        while (low<=high){
            int mid=low+(high-low)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]>target) high=mid-1;
            else low=mid+1;
        } return -1;
    }
};