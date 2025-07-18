#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumLength(std::vector<int>& nums, int k) {
        std::vector<std::vector<int>> dp(k, std::vector<int>(k, 0));
        int max_len = 0;

        for (int num : nums) {
            int rem = num % k;
            for (int prev_rem = 0; prev_rem < k; ++prev_rem) {
                // Case 1: Subsequence alternates between prev_rem and rem
                dp[prev_rem][rem] = std::max(dp[prev_rem][rem], dp[rem][prev_rem] + 1);
            }
            // Case 2: Subsequence where all elements have the same remainder
            dp[rem][rem] = std::max(dp[rem][rem], 1); // For a subsequence of length 1 or extending an existing one
        }

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                max_len = std::max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
};
