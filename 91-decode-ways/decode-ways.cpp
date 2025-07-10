using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0; 
        }

        int n = s.length();
        vector<int> dp(n + 1, 0);

        dp[0] = 1; 
        dp[1] = (s[0] == '0') ? 0 : 1; 

        for (int i = 2; i <= n; ++i) {
            // Check for single digit decoding
            int one_digit = stoi(s.substr(i - 1, 1));
            if (one_digit >= 1 && one_digit <= 9) {
                dp[i] += dp[i - 1];
            }

            // Check for two digit decoding
            int two_digits = stoi(s.substr(i - 2, 2));
            if (two_digits >= 10 && two_digits <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};