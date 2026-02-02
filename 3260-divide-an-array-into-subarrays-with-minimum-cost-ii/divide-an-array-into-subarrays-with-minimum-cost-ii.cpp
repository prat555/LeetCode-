class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        k--; // We need k-1 more starting points after nums[0]
        
        multiset<int> left, right;
        long long current_sum = 0;

        // Helper to balance: move smallest from right to left
        auto r2l = [&]() {
            int val = *right.begin();
            current_sum += val;
            left.insert(val);
            right.erase(right.begin());
        };

        // Helper to balance: move largest from left to right
        auto l2r = [&]() {
            int val = *left.rbegin();
            current_sum -= val;
            right.insert(val);
            left.erase(prev(left.end()));
        };

        // 1. Initial Window [1, dist + 1]
        for (int i = 1; i <= dist + 1; ++i) {
            left.insert(nums[i]);
            current_sum += nums[i];
        }

        // 2. Reduce left set to exactly k-1 smallest elements
        while (left.size() > k) l2r();

        long long min_cost = current_sum;

        // 3. Sliding Window
        for (int i = dist + 2; i < n; ++i) {
            // Remove outgoing element nums[i - dist - 1]
            int out = nums[i - dist - 1];
            auto it = left.find(out);
            if (it != left.end()) {
                current_sum -= out;
                left.erase(it);
            } else {
                right.erase(right.find(out));
            }

            // Add incoming element nums[i]
            // Optimization: if new element is smaller than max of left, it belongs there
            if (!left.empty() && nums[i] < *left.rbegin()) {
                current_sum += nums[i];
                left.insert(nums[i]);
            } else {
                right.insert(nums[i]);
            }

            // 4. Rebalance sets to maintain exactly k-1 elements in 'left'
            while (left.size() < k && !right.empty()) r2l();
            while (left.size() > k) l2r();

            min_cost = min(min_cost, current_sum);
        }

        return (long long)nums[0] + min_cost;
    }
};
