class Solution {
public:
    bool isSubsequence(string s, string t) {
        int w=0,k=0;
        while (k<t.length()){
            if (s[w]==t[k]){
                k++;
                w++;
            } else k++;
        } if (w==s.length()) return true;
        else return false;
    }
};