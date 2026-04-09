#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = max(1, (int)sqrt(n));

        // diff[k][r][j] = multiplier diff for step-k, residue-r, at position j
        // j here is the actual array index (not subsequence index)
        // We store diff over actual indices, but only apply within residue class
        // So diff[k][r] has size ceil((n - r) / k) + 1 (subsequence length + 1)
        // For simplicity, index by actual array index / k (position in subsequence)
        
        // diff[k][r] -> difference array over positions 0,1,2,... in the subsequence
        // subsequence for (k,r): indices r, r+k, r+2k, ...
        // length = (n - 1 - r) / k + 1  if r < n else 0

        // Use flat: diff_arr[k][r] = vector of length (subseq_len + 1)
        // But B can be up to ~316, and sum of k*k for k=1..B ~ B^3/3 ~ 10^7: too much
        // Instead index diff by actual array index (size n+1), sweep only residue indices

        vector<vector<long long>> diff(B + 1, vector<long long>(n + 1, 1));

        auto modinv = [&](long long a) {
            return power(a, MOD - 2, MOD);
        };

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            long long v = q[3];

            if (k > B) {
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (long long)nums[idx] * v % MOD;
                }
            } else {
                // Encode in diff[k]: mark start at l, undo after last hit
                // Key fix: undo position must also be in the same residue class
                int last = l + ((r - l) / k) * k;
                int next = last + k; // next index in same residue class after range
                diff[k][l] = diff[k][l] * v % MOD;
                if (next <= n) {
                    diff[k][next] = diff[k][next] * modinv(v) % MOD;
                }
            }
        }

        for (int k = 1; k <= B; k++) {
            // For each residue class, do a prefix product sweep
            // visiting only indices r, r+k, r+2k, ...
            for (int r = 0; r < k && r < n; r++) {
                long long running = 1;
                for (int i = r; i < n; i += k) {
                    running = running * diff[k][i] % MOD;
                    nums[i] = (long long)nums[i] * running % MOD;
                }
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};