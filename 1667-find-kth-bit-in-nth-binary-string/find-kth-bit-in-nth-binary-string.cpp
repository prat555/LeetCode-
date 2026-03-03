class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for (int i=1; i<n; i++){
            string m="";
            for (int j=s.size()-1; j>=0; j--) m+=s[j]^1;
            s+="1"+m;
        } return s[k-1];
    }
};