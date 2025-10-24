#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        // generate all numerically-balanced numbers up to 10 digits
        // (since 32-bit signed int max has 10 digits)
        set<long long> results; // keep sorted & unique

        // digits 1..9 mapped to bits 0..8
        for (int mask = 1; mask < (1 << 9); ++mask) {
            int total_len = 0;
            for (int d = 1; d <= 9; ++d) {
                if (mask & (1 << (d - 1))) total_len += d;
            }
            if (total_len == 0 || total_len > 10) continue;

            // build vector of digits (each digit d repeated d times)
            vector<int> digits;
            digits.reserve(total_len);
            for (int d = 1; d <= 9; ++d) {
                if (mask & (1 << (d - 1))) {
                    for (int k = 0; k < d; ++k) digits.push_back(d);
                }
            }

            sort(digits.begin(), digits.end());
            // enumerate unique permutations
            do {
                long long val = 0;
                for (int dig : digits) {
                    val = val * 10 + dig;
                    if (val > INT_MAX) break; // avoid overflow / unnecessary values
                }
                if (val <= INT_MAX) results.insert(val);
            } while (next_permutation(digits.begin(), digits.end()));
        }

        // find smallest number > n
        auto it = results.upper_bound((long long)n);
        if (it != results.end()) return (int)(*it);
        // In theory there should always be an answer within int range for problem constraints,
        // but fallback - return -1 if none found.
        return -1;
    }
};
