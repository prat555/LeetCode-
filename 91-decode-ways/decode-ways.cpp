class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0')?0:1;
        for(int i = 2; i<=n; i++) {
            if(s[i-1] != '0') dp[i] += dp[i-1];
            int n = stoi(s.substr(i-2, 2));
            if(n>9 && n<27) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};