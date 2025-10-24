class Solution {
public:
    int nextBeautifulNumber(int n) {
        set<long long> results;
        for (int mask = 1; mask < (1 << 9); ++mask) {
            int total_len = 0;
            for (int d = 1; d <= 9; ++d)
                if (mask & (1 << (d - 1))) total_len += d;
            if (total_len == 0 || total_len > 10) continue;
            vector<int> digits;
            digits.reserve(total_len);
            for (int d = 1; d <= 9; ++d)
                if (mask & (1 << (d - 1)))
                    for (int k = 0; k < d; ++k) digits.push_back(d);
            sort(digits.begin(), digits.end());
            do {
                long long val = 0;
                for (int dig : digits) {
                    val = val * 10 + dig;
                    if (val > INT_MAX) break;
                }
                if (val <= INT_MAX) results.insert(val);
            } while (next_permutation(digits.begin(), digits.end()));
        }
        auto it = results.upper_bound((long long)n);
        if (it != results.end()) return (int)(*it);
        return -1;
    }
};
