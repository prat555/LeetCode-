class Solution {
public:
    int longestBalanced(string s) {
        int ans=1;
        for (int i=0; i<s.size(); i++){
            unordered_map<char, int> freq;
            for (int j=i; j<s.size(); j++){
                freq[s[j]]++;
                int mn= INT_MAX, mx= INT_MIN;
                for (auto &p: freq){
                    mn=min(mn,p.second);
                    mx=max(mx,p.second);
                } if (mn==mx) ans=max(ans,j-i+1);
            }
        } return ans;
    }
};