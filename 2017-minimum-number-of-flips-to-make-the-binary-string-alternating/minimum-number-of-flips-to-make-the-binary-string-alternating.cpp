class Solution {
public:
    int minFlips(string s) {
        int n=s.size(), cnt=0;
        string target="01";
        for (int i=0; i<n; ++i) {
            if (s[i]!=target[i%2]) ++cnt;
        } int ans=min(cnt, n-cnt);
        for (int i=0; i<n; ++i) {
            if (s[i]!=target[i&1]) --cnt;
            if (s[i]!=target[(i+n)&1]) ++cnt;
            ans=min({ans, cnt, n-cnt});
        } return ans;
    }
};