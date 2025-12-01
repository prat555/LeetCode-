class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            // If left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // target in left sorted half
                } else {
                    left = mid + 1;  // target in right half
                }
            } else {
                // Right half must be sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // target in right sorted half
                } else {
                    right = mid - 1; // target in left half
                }
            }
        }
        return -1;
    }
};
