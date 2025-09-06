#include <vector>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            ans += (getOperations(r) - getOperations(l - 1) + 1) / 2;
        }
        return ans;
    }

private:
    // Computes total operations needed to reduce all numbers from 1 to n to zero
    long long getOperations(long long n) {
        if (n <= 0) return 0;
        long long res = 0;
        long long powerOfFour = 1;
        int ops = 0;

        while (powerOfFour <= n) {
            long long left = powerOfFour;
            long long right = min(n, powerOfFour * 4 - 1);
            ++ops;
            res += (right - left + 1) * ops;
            powerOfFour *= 4;
        }
        return res;
    }
};
