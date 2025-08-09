#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int p = 0;
        while (p + 1 < n && nums[p] < nums[p + 1]) {
            p++;
        }
        if (p == 0 || p >= n - 1) return false;

        int q = n - 1;
        while (q - 1 >= 0 && nums[q - 1] < nums[q]) {
            q--;
        }
        if (q == n - 1 || q <= 0) return false;

        if (!(p < q)) return false;

        for (int i = p; i < q; i++) {
            if (nums[i] <= nums[i + 1]) {
                return false;
            }
        }

        return true;
    }
};
