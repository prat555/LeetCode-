class Solution {
public:
    int minOperations(string s) {
        int cnt=0;
        for (int i=1; i<s.size(); i++){
            if (s[i]==s[i-1]){
                s[i]^=1;
                cnt++;
            } 
        } return min(cnt, (int)s.size()-cnt);
    }
};