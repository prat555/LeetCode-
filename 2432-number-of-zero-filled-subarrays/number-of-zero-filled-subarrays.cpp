class Solution {
public:
    long long zeroFilledSubarray(std::vector<int>& nums) {
        long long total_subarrays = 0;
        long long current_consecutive_zeros = 0;

        for (int num : nums) {
            if (num == 0) {
                current_consecutive_zeros++;
                total_subarrays += current_consecutive_zeros;
            } else {
                current_consecutive_zeros = 0;
            }
        }
        return total_subarrays;
    }
};