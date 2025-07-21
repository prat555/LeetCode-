class Solution {
public:
    string makeFancyString(string s) {
        string ans; 
        for (char c : s) { 
            if (ans.length() >= 2 && ans.back() == c && ans[ans.length() - 2] == c) {
                continue;
            } else {
                ans.push_back(c); 
            }
        }
        return ans; 
    }
};